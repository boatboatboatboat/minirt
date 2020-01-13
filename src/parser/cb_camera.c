/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:48:35 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:52:42 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	cb_camera(
		char **input,
		t_scene *scene)
{
	t_bool		result;
	t_camera	camera;
	t_vec3		from;
	t_vec3		to;

	result = (expectc(input, 'c')
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &from)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &to)
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &camera.fov));
	if (result)
		camera.cframe = mat4_lookat(from, vec3_add(from, to));
	if (result && vector_push(&scene->cameras, &camera))
		return (true);
	return (result);
}
