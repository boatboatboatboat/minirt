/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:46:22 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 22:16:11 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool	is_normal(t_vec3 self)
{
	t_f64	magnitude;

	magnitude = vec3_magnitude(self);
	return (magnitude > (1 - EPSILON) && magnitude < (1 + EPSILON));
}

t_bool			add_squares(
		t_renderable *self,
		t_square *front,
		t_scene *scene)
{
	t_square	back;
	t_vec3		normal;

	front->size /= 2.0;
	self->tag = Square;
	self->var.square = *front;
	self->intersect = square_intersect;
	self->normal = square_normal;
	self->var.square.other = scene->objects.size + 1;
	if (!vector_push(&scene->objects, self))
		return (false);
	normal = vec3_mulf(front->rotation, 2.0 * EPSILON);
	back = *front;
	back.center = vec3_sub(front->center, normal);
	back.rotation = vec3_unm(front->rotation);
	back.other = scene->objects.size - 1;
	self->var.square = back;
	if (!vector_push(&scene->objects, self))
		return (false);
	return (true);
}

t_bool			cb_square(
		char **input,
		t_scene *scene)
{
	t_bool			result;
	t_square		square;
	t_renderable	obj;

	result = (expects(input, "sq")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &square.center)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &square.rotation)
			&& is_normal(square.rotation)
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &square.size) && square.size > 0.0
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result && !add_squares(&obj, &square, scene))
		return (false);
	return (result);
}
