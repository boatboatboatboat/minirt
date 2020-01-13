/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:13:23 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/08 00:39:15 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

static void	relocate_triangle(
		t_triangle *tri,
		t_draw_obj *drawer,
		t_vec3 offset)
{
	t_vec3		centroid;
	t_triangle	*bck;

	centroid = vec3_add(tri->v0, vec3_add(tri->v1, tri->v2));
	vector_getr(&drawer->scene->objects, tri->other, (void**)&bck);
	tri->v0 = vec3_add(tri->v0, offset);
	tri->v1 = vec3_add(tri->v1, offset);
	tri->v2 = vec3_add(tri->v2, offset);
	bck->v0 = vec3_add(bck->v0, offset);
	bck->v1 = vec3_add(bck->v1, offset);
	bck->v2 = vec3_add(bck->v2, offset);
}

void		change_obj_pos(
		t_draw_obj *drawer,
		t_vec3 offset)
{
	t_render_variant	*var;
	t_renderable		*ovr;

	if (drawer->selection == NULL)
		return ;
	var = &drawer->selection->var;
	if (drawer->selection->tag == Sphere || drawer->selection->tag == Plane)
		var->sphere.center = vec3_add(var->sphere.center, offset);
	else if (drawer->selection->tag == Triangle)
		relocate_triangle(&var->triangle, drawer, offset);
	else if (drawer->selection->tag == Square)
	{
		var->square.center = vec3_add(var->square.center, offset);
		vector_getr(
				&drawer->scene->objects, var->square.other, (void**)&ovr);
		ovr->var.square.center = vec3_add(ovr->var.square.center, offset);
	}
	else if (drawer->selection->tag == Cylinder)
	{
		var->cylinder.center = vec3_add(var->cylinder.center, offset);
		vector_getr(
				&drawer->scene->objects, var->cylinder.other, (void**)&ovr);
		ovr->var.cylinder.center = vec3_add(ovr->var.cylinder.center, offset);
	}
}
