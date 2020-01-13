/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 05:25:43 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/07 22:37:45 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_color	apply_light(
		t_scene *scene,
		t_light light,
		t_renderable *hit,
		t_vec3 hitp)
{
	t_f64	dist;
	t_ray	shadow;
	t_vec3	normal;
	t_vec3	dir;
	t_f64	intensity;

	normal = hit->normal(hit, &hitp);
	dir = vec3_sub(light.position, hitp);
	shadow = ray_new(vec3_add(hitp, vec3_mulf(normal, EPSILON / 2.0)),
			vec3_unit(dir));
	if (!scene_cast_ray(scene, &shadow, NULL, &dist) \
	|| dist > vec3_magnitude(dir))
	{
		intensity = fmin(light.brightness / (4.0 * M_PI * vec3_norm(dir)) *
				fmax(vec3_dot(normal, dir), 0.0) * LIGHT_MULT, 1.0);
		return (color_mul(hit->color, light.color, intensity));
	}
	return (color_new(0, 0, 0));
}

t_color	apply_lighting(
		t_scene *scene,
		t_renderable *hit,
		t_vec3 hitp)
{
	t_size	idx;
	t_light	light;
	t_color	cmcol;

	idx = 0;
	cmcol = color_new(0, 0, 0);
	while (idx < scene->lights.size)
	{
		(void)vector_get(&scene->lights, idx, &light);
		cmcol = color_add(cmcol, apply_light(scene, light, hit, hitp));
		idx += 1;
	}
	return (cmcol);
}

t_color	get_pixel(
		t_scene *scene,
		t_size resolution[2],
		t_size x,
		t_size y)
{
	t_renderable	*hit;
	t_f64			distance;
	t_color			cmcol;
	t_ray			ray;

	ray = screen_ray_res(scene, resolution, x, y);
	cmcol = color_new(0, 0, 0);
	if (scene_cast_ray(scene, &ray, &hit, &distance))
	{
		cmcol = color_add(cmcol, color_mul(hit->color, scene->ambient_color,
				scene->ambient_brightness));
		cmcol = color_add(cmcol, apply_lighting(scene, hit,
				vec3_add(ray.origin, vec3_mulf(ray.direction, distance))));
	}
	return (cmcol);
}

t_color	cap_sized_color(
		t_size scale,
		t_size col[3])
{
	col[0] /= scale * scale;
	col[1] /= scale * scale;
	col[2] /= scale * scale;
	col[0] = col[0] > 255 ? 255 : col[0];
	col[1] = col[1] > 255 ? 255 : col[1];
	col[2] = col[2] > 255 ? 255 : col[2];
	return (color_new(col[0], col[1], col[2]));
}

void	render_pixel(
		t_scene *scene,
		t_size x,
		t_size y)
{
	t_size	scaled[2];
	t_size	evt_col[3];
	t_size	res[2];
	t_color	tmp;

	res[0] = scene->resolution[0] * scene->scale;
	res[1] = scene->resolution[1] * scene->scale;
	ft_bzero(evt_col, 3 * sizeof(t_size));
	ft_bzero(scaled, 2 * sizeof(t_size));
	while (scaled[0] < scene->scale)
	{
		scaled[1] = 0;
		while (scaled[1] < scene->scale)
		{
			tmp = get_pixel(scene, res, x * scene->scale + scaled[1],
					y * scene->scale + scaled[1]);
			evt_col[0] += tmp.r;
			evt_col[1] += tmp.g;
			evt_col[2] += tmp.b;
			scaled[1] += 1;
		}
		scaled[0] += 1;
	}
	tmp = cap_sized_color(scene->scale, evt_col);
	(void)vector_set(&scene->buffer, y * scene->resolution[0] + x, &tmp);
}
