/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_angles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 00:46:23 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 00:57:21 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>
#include <math.h>

static t_mat4	x_angle(t_f64 x)
{
	return (mat4_new(vec3_right(),
			vec3_new(0.0, cos(x), -sin(x)),
			vec3_new(0.0, sin(x), cos(x)),
			vec3_zero()));
}

static t_mat4	y_angle(t_f64 y)
{
	return (mat4_new(vec3_new(cos(y), 0.0, sin(y)),
			vec3_up(),
			vec3_new(-sin(y), 0.0, cos(y)),
			vec3_zero()));
}

static t_mat4	z_angle(t_f64 z)
{
	return (mat4_new(vec3_new(cos(z), -sin(z), 0.0),
			vec3_new(sin(z), cos(z), 0.0),
			vec3_forward(),
			vec3_zero()));
}

t_mat4			mat4_angles(
		t_f64 x,
		t_f64 y,
		t_f64 z)
{
	return (mat4_mul(mat4_mul(x_angle(x), y_angle(y)), z_angle(z)));
}
