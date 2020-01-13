/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_lookat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:49:53 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 08:44:16 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mat4.h>

static t_mat4	quat_to_matrix(
		t_f64 w,
		t_f64 x,
		t_f64 y,
		t_f64 z)
{
	t_vec3			m0;
	t_vec3			m1;
	t_vec3			m2;

	m0 = vec3_new(1.0 - 2.0 * (y * y + z * z), \
		2.0 * (x * y - z * w), 2.0 * (x * z + y * w));
	m1 = vec3_new(2.0 * (x * y + z * w), 1.0 - 2.0 * (x * x + z * z), \
		2.0 * (y * z - x * w));
	m2 = vec3_new(2.0 * (x * z - y * w), 2.0 * (y * z + x * w), \
		1.0 - 2.0 * (x * x + y * y));
	return (mat4_new(m0, m1, m2, vec3_zero()));
}

static t_mat4	lookat_by_matrix(
		t_vec3 position,
		t_vec3 target)
{
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;

	forward = vec3_unit(vec3_sub(position, target));
	right = vec3_cross(g_vec3_up, forward);
	up = vec3_cross(forward, right);
	return (mat4_new(right, up, forward, position));
}

static t_mat4	lookat_by_quat(
		t_vec3 position,
		t_vec3 target)
{
	t_f64			angle;
	t_f64			normal;
	t_vec3			axis;
	t_vec3			to;
	t_mat4			from_quat;

	to = vec3_unit(vec3_sub(target, position));
	angle = acos(vec3_dot(g_vec3_forward, to));
	axis = vec3_cross(g_vec3_forward, to);
	axis = vec3_unit(axis);
	if (vec3_norm(axis) > -EPSILON && vec3_norm(axis) < EPSILON)
		axis = vec3_up();
	normal = sqrt(1.0 / (pow(cos(angle * 0.5), 2.0) + pow(axis.x \
			* sin(angle * 0.5), 2.0) + pow(axis.y * sin(angle * 0.5), 2.0) \
			+ pow(axis.z * sin(angle * 0.5), 2.0)));
	from_quat = quat_to_matrix(cos(angle * 0.5) * normal,
			axis.x * sin(angle * 0.5) * normal,
			axis.y * sin(angle * 0.5) * normal,
			axis.z * sin(angle * 0.5) * normal);
	return (mat4_mul_rbx(from_quat, position));
}

t_mat4			mat4_lookat(
		t_vec3 position,
		t_vec3 target)
{
	t_vec3 unit;

	unit = vec3_unit(vec3_sub(position, target));
	if (unit.x == 0.0 && unit.z == 0.0 && (unit.y == 1.0 || unit.y == -1.0))
		return (lookat_by_quat(position, target));
	else
		return (lookat_by_matrix(position, target));
}
