/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 22:04:54 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 02:03:35 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool	is_normal(t_vec3 self)
{
	t_f64	magnitude;

	magnitude = vec3_magnitude(self);
	return (magnitude > (1 - EPSILON) && magnitude < (1 + EPSILON));
}

t_bool			cb_plane(
		char **input,
		t_scene *scene)
{
	t_bool			result;
	t_plane			plane;
	t_renderable	obj;

	result = (expects(input, "pl")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &plane.center)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &plane.rotation)
			&& is_normal(plane.rotation)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result)
	{
		plane.rotation = vec3_unm(plane.rotation);
		obj.var.plane = plane;
		obj.tag = Plane;
		obj.intersect = plane_intersect;
		obj.normal = plane_normal;
	}
	return (result && vector_push(&scene->objects, &obj));
}
