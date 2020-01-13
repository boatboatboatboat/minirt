/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 02:37:24 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 05:19:08 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool	is_normal(t_vec3 self)
{
	t_f64	magnitude;

	magnitude = vec3_magnitude(self);
	return (magnitude > (1 - EPSILON) && magnitude < (1 + EPSILON));
}

t_bool			add_cylinders(
		t_renderable *self,
		t_cylinder *outer,
		t_scene *scene)
{
	t_cylinder		inner;

	self->var.cylinder.other = scene->objects.size + 1;
	if (!vector_push(&scene->objects, self))
		return (false);
	inner = *outer;
	inner.direction = false;
	inner.radius -= EPSILON * 2.0;
	inner.other = scene->objects.size - 1;
	self->var.cylinder = inner;
	if (!vector_push(&scene->objects, self))
		return (false);
	return (true);
}

static void		init_obj(
		t_renderable *obj,
		t_cylinder *cylinder)
{
	cylinder->radius /= 2.0;
	cylinder->direction = true;
	obj->tag = Cylinder;
	obj->var.cylinder = *cylinder;
	obj->intersect = cylinder_intersect;
	obj->normal = cylinder_normal;
}

t_bool			cb_cylinder(
		char **input,
		t_scene *scene)
{
	t_bool			result;
	t_cylinder		cylinder;
	t_renderable	obj;

	result = (expects(input, "cy")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &cylinder.center)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &cylinder.rotation)
			&& is_normal(cylinder.rotation)
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &cylinder.radius) && cylinder.radius > 0.0
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &cylinder.height) && cylinder.height > 0.0
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result)
		init_obj(&obj, &cylinder);
	if (result && !add_cylinders(&obj, &cylinder, scene))
		return (false);
	return (result);
}
