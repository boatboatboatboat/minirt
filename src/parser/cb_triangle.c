/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 03:52:32 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 23:09:28 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	add_triangles(
		t_renderable *self,
		t_triangle *front,
		t_scene *scene)
{
	t_triangle	back;
	t_vec3		normal;

	front->other = scene->objects.size + 1;
	front->direction = true;
	self->var.triangle = *front;
	self->tag = Triangle;
	self->intersect = triangle_intersect;
	self->normal = triangle_normal;
	if (!vector_push(&scene->objects, self))
		return (false);
	normal = vec3_mulf(triangle_normal(self, &front->v0), 2.0 * -EPSILON);
	back.direction = false;
	back.other = scene->objects.size - 1;
	back.v0 = vec3_add(front->v0, normal);
	back.v1 = vec3_add(front->v1, normal);
	back.v2 = vec3_add(front->v2, normal);
	self->var.triangle = back;
	if (!vector_push(&scene->objects, self))
		return (false);
	return (true);
}

t_bool	cb_triangle(
		char **input,
		t_scene *scene)
{
	t_bool			result;
	t_triangle		triangle;
	t_renderable	obj;

	result = (expects(input, "tr")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &triangle.v0)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &triangle.v1)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &triangle.v2)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result && !add_triangles(&obj, &triangle, scene))
		return (false);
	return (result);
}
