/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 07:29:01 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 07:29:01 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>

static void	change_obj_size(
		t_draw_obj *drawer,
		t_f64 step)
{
	t_render_variant	*var;
	t_renderable		*ovr;

	if (drawer->selection == NULL)
		return ;
	var = &drawer->selection->var;
	if (drawer->selection->tag == Sphere)
		var->sphere.radius = fmax(.1, var->sphere.radius + step);
	else if (drawer->selection->tag == Square)
	{
		var->square.size = fmax(.1, var->square.size + step);
		vector_getr(
				&drawer->scene->objects, var->square.other, (void**)&ovr);
		ovr->var.square.size = fmax(.1, ovr->var.square.size + step);
	}
	else if (drawer->selection->tag == Cylinder)
	{
		var->cylinder.radius = fmax(.1, var->cylinder.radius + step);
		var->cylinder.height = fmax(.1, var->cylinder.height + step);
		vector_getr(
				&drawer->scene->objects, var->cylinder.other, (void**)&ovr);
		ovr->var.cylinder.radius = fmax(.1, ovr->var.cylinder.radius + step);
		ovr->var.cylinder.height = fmax(.1, ovr->var.cylinder.height + step);
	}
}

void		increase_obj_size(t_draw_obj *drawer)
{
	change_obj_size(drawer, RESIZE_STEP);
}

void		decrease_obj_size(t_draw_obj *drawer)
{
	change_obj_size(drawer, -RESIZE_STEP);
}
