/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mul_rbx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:19:20 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 23:26:33 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_mul_rbx(
		t_mat4 self,
		t_vec3 other)
{
	t_vec3			right;
	t_vec3			up;
	t_vec3			forward;
	t_vec3			position;
	t_mat4			out;

	right = mat4_right_vec(self);
	up = mat4_up_vec(self);
	forward = mat4_look_vec(self);
	position = mat4_pos(self);
	position = vec3_add(position, other);
	out = mat4_new(right, up, forward, position);
	return (out);
}
