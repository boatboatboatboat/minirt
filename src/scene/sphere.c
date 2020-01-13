/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:55:51 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/04 19:23:15 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_bool	sphere_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_vec3	line;
	t_f64	tca;
	t_f64	tmp;

	line = vec3_sub(self->var.sphere.center, ray->origin);
	tca = vec3_dot(line, ray->direction);
	if (tca < 0.0)
		return (false);
	tmp = vec3_dot(line, line) - pow(tca, 2.0);
	if (tmp > pow(self->var.sphere.radius, 2.0))
		return (false);
	tmp = sqrt(pow(self->var.sphere.radius, 2.0) - tmp);
	line.x = tca - tmp;
	line.y = tca + tmp;
	if (line.x > line.y)
	{
		tmp = line.x;
		line.x = line.y;
		line.y = tmp;
	}
	if (line.x < 0.0 && line.y < 0.0)
		return (false);
	*out = line.x < 0.0 ? line.y : line.x;
	return (true);
}

t_vec3	sphere_normal(
		struct s_renderable *self,
		t_vec3 *hit)
{
	return (vec3_unit(vec3_sub(*hit, self->var.sphere.center)));
}
