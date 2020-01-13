/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:37:54 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 09:20:26 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool	scene_init(t_scene *scene)
{
	t_bool	res;

	res = vector_new(&scene->lights, sizeof(t_light));
	res = vector_new(&scene->cameras, sizeof(t_camera)) && res;
	res = vector_new(&scene->objects, sizeof(t_renderable)) && res;
	scene->scale = 1;
	scene->current_camera = 0;
	if (!res)
	{
		vector_destroy(&scene->lights);
		vector_destroy(&scene->cameras);
		vector_destroy(&scene->objects);
	}
	return (res);
}

static t_bool	cb_scene_normal(
		char **input,
		t_scene *out)
{
	t_bool	fr;

	if (!scene_init(out))
		return (false);
	fr = false;
	out->set = 0;
	skip_atleast(input, '\n', 0);
	while (1)
	{
		if (fr && !skip_atleast(input, '\n', 1))
			break ;
		if (!(cb_resolution(input, out) || cb_ambient(input, out) \
			|| cb_cylinder(input, out) || cb_light(input, out) \
			|| cb_sphere(input, out) || cb_plane(input, out) \
			|| cb_camera(input, out) || cb_triangle(input, out)
			|| cb_square(input, out)))
			break ;
		fr = true;
	}
	skip_atleast(input, '\n', 0);
	return (out->set == ALL_SET && out->cameras.size != 0);
}

t_bool			cb_scene(
		char **input,
		t_scene *out)
{
	t_bool	result;

	result = cb_scene_normal(input, out);
	if (result)
		if (!vector_with_capacity(&out->buffer, sizeof(t_color),
				out->resolution[0] * out->resolution[1]))
		{
			vector_destroy(&out->lights);
			vector_destroy(&out->cameras);
			vector_destroy(&out->objects);
			return (false);
		}
	return (result);
}
