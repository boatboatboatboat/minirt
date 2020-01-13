/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:56:14 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 02:10:57 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_bool	plane_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_plane	plane;
	t_f64	denominator;
	t_f64	t;

	plane = self->var.plane;
	denominator = vec3_dot(plane.rotation, ray->direction);
	if (denominator > EPSILON)
	{
		t = vec3_dot(vec3_sub(plane.center, ray->origin), plane.rotation)
				/ denominator;
		if (t >= 0.0)
		{
			*out = t;
			return (true);
		}
	}
	return (false);
}

t_vec3	plane_normal(
		struct s_renderable *self,
		t_vec3 *hit)
{
	(void)hit;
	return (vec3_unm(self->var.plane.rotation));
}
