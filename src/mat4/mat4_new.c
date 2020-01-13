/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:13:33 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 16:27:10 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_new(
		t_vec3 right,
		t_vec3 up,
		t_vec3 look,
		t_vec3 pos)
{
	t_mat4	out;

	out.inner[0][0] = right.x;
	out.inner[0][1] = right.y;
	out.inner[0][2] = right.z;
	out.inner[1][0] = up.x;
	out.inner[1][1] = up.y;
	out.inner[1][2] = up.z;
	out.inner[2][0] = look.x;
	out.inner[2][1] = look.y;
	out.inner[2][2] = look.z;
	out.inner[3][0] = pos.x;
	out.inner[3][1] = pos.y;
	out.inner[3][2] = pos.z;
	out.inner[0][3] = 0.0;
	out.inner[1][3] = 0.0;
	out.inner[2][3] = 0.0;
	out.inner[3][3] = 1.0;
	return (out);
}
