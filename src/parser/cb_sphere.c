/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:38:16 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 03:23:57 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	cb_sphere(
		char **input,
		t_scene *scene)
{
	t_bool			result;
	t_sphere		sphere;
	t_renderable	obj;

	result = (expects(input, "sp")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &sphere.center)
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &sphere.radius)
			&& (sphere.radius / 2.0) > 0.0
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result)
	{
		sphere.radius /= 2.0;
		obj.var.sphere = sphere;
		obj.tag = Sphere;
		obj.intersect = sphere_intersect;
		obj.normal = sphere_normal;
	}
	if (result && !vector_push(&scene->objects, &obj))
		return (false);
	return (result);
}
