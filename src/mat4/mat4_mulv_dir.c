/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mulv_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:09:16 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/04 19:39:21 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_vec3	mat4_mulv_dir(
		t_mat4 self,
		t_vec3 dir)
{
	t_f64	x;
	t_f64	y;
	t_f64	z;

	x = dir.x * self.inner[0][0] + dir.y * self.inner[1][0]
			+ dir.z * self.inner[2][0];
	y = dir.x * self.inner[0][1] + dir.y * self.inner[1][1]
			+ dir.z * self.inner[2][1];
	z = dir.x * self.inner[0][2] + dir.y * self.inner[1][2]
			+ dir.z * self.inner[2][2];
	return (vec3_new(x, y, z));
}
