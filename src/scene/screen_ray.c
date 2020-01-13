/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 07:22:51 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 03:59:55 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_ray	screen_ray(
		t_scene *scene,
		t_size x,
		t_size y)
{
	t_f64		scale;
	t_f64		ratio;
	t_camera	camera;
	t_vec3		dir;

	vector_get(&scene->cameras, scene->current_camera, &camera);
	camera.cframe = mat4_mul(mat4_angles(
			fmod(camera.adjust.x, M_PI * 2),
			fmod(camera.adjust.y, M_PI * 2),
			fmod(camera.adjust.z, M_PI * 2)), camera.cframe);
	scale = tan(rad(camera.fov * 0.5));
	ratio = (t_f64)scene->resolution[0] / (t_f64)scene->resolution[1];
	dir = vec3_new((2.0 * (x + 0.5) / (t_f64)scene->resolution[0] - 1.0)
			* ratio * scale, (1.0 - 2.0 * (y + 0.5) /
			(t_f64)scene->resolution[1]) * scale, -1.0);
	dir = vec3_unit(mat4_mulv_dir(camera.cframe, dir));
	return (ray_new(mat4_pos(camera.cframe), dir));
}

t_ray	screen_ray_res(
		t_scene *scene,
		const t_size resolution[2],
		t_size x,
		t_size y)
{
	t_f64		scale;
	t_f64		ratio;
	t_camera	camera;
	t_vec3		dir;

	vector_get(&scene->cameras, scene->current_camera, &camera);
	camera.cframe = mat4_mul(mat4_angles(
			fmod(camera.adjust.x, M_PI * 2),
			fmod(camera.adjust.y, M_PI * 2),
			fmod(camera.adjust.z, M_PI * 2)), camera.cframe);
	scale = tan(rad(camera.fov * 0.5));
	ratio = (t_f64)resolution[0] / (t_f64)resolution[1];
	dir = vec3_new((2.0 * (x + 0.5) / (t_f64)resolution[0] - 1.0)
			* ratio * scale, (1.0 - 2.0 * (y + 0.5) /
			(t_f64)resolution[1]) * scale, -1.0);
	dir = vec3_unit(mat4_mulv_dir(camera.cframe, dir));
	return (ray_new(mat4_pos(camera.cframe), dir));
}
