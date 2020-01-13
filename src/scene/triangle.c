/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 03:26:36 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 23:09:28 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>

t_bool			real_triangle_intersect(
		t_triangle *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_vec3	v0v12[2];
	t_vec3	ptqvec[3];
	t_f64	uvt[3];
	t_f64	det;

	v0v12[0] = vec3_sub(self->v1, self->v0);
	v0v12[1] = vec3_sub(self->v2, self->v0);
	ptqvec[0] = vec3_cross(ray->direction, v0v12[1]);
	det = vec3_dot(v0v12[0], ptqvec[0]);
	if (fabs(det) < EPSILON)
		return (false);
	ptqvec[1] = vec3_sub(ray->origin, self->v0);
	uvt[0] = vec3_dot(ptqvec[1], ptqvec[0]) / det;
	if (uvt[0] < 0.0 || uvt[0] > 1.0)
		return (false);
	ptqvec[2] = vec3_cross(ptqvec[1], v0v12[0]);
	uvt[1] = vec3_dot(ray->direction, ptqvec[2]) / det;
	if (uvt[1] < 0.0 || uvt[0] + uvt[1] > 1.0)
		return (false);
	uvt[2] = vec3_dot(v0v12[1], ptqvec[2]) / det;
	if (uvt[2] <= 0.0)
		return (false);
	*out = uvt[2];
	return (true);
}

t_bool			triangle_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_triangle	*front;

	front = &self->var.triangle;
	return (real_triangle_intersect(front, ray, out));
}

t_vec3			triangle_normal(
		struct s_renderable *self,
		t_vec3 *hit)
{
	t_triangle	*triangle;
	t_vec3		va;
	t_vec3		vb;
	t_vec3		result;

	(void)hit;
	triangle = &self->var.triangle;
	if (!triangle->direction)
	{
		va = vec3_sub(triangle->v1, triangle->v0);
		vb = vec3_sub(triangle->v2, triangle->v0);
	}
	else
	{
		va = vec3_sub(triangle->v1, triangle->v2);
		vb = vec3_sub(triangle->v0, triangle->v2);
	}
	result = vec3_unit(vec3_cross(va, vb));
	return (result);
}
