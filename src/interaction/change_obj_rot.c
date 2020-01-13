/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:13:23 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 23:36:55 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

static t_vec3	rotate(
		t_vec3 rotation,
		t_vec3 *offset)
{
	t_mat4	rotator;

	rotator = mat4_lookat(vec3_zero(), rotation);
	rotator = mat4_mul(rotator, mat4_angles(
			rad(offset->x), rad(offset->y), rad(offset->z)));
	return (mat4_look_vec(rotator));
}

void			change_obj_rot(
		t_draw_obj *drawer,
		t_vec3 offset)
{
	t_render_variant	*var;
	t_renderable		*ovr;

	if (drawer->selection == NULL)
		return ;
	var = &drawer->selection->var;
	if (drawer->selection->tag == Plane)
		var->plane.rotation = rotate(var->plane.rotation, &offset);
	else if (drawer->selection->tag == Square)
	{
		var->square.rotation = rotate(var->square.rotation, &offset);
		vector_getr(
				&drawer->scene->objects, var->square.other, (void**)&ovr);
		ovr->var.square.rotation = vec3_unm(var->square.rotation);
		ovr->var.square.center = vec3_sub(var->square.center, vec3_mulf(
				var->square.rotation, 2.0 * EPSILON));
	}
	else if (drawer->selection->tag == Cylinder)
	{
		var->cylinder.rotation = rotate(var->cylinder.rotation, &offset);
		vector_getr(
				&drawer->scene->objects, var->cylinder.other, (void**)&ovr);
		ovr->var.cylinder.rotation = var->cylinder.rotation;
	}
}
