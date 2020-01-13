/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_addv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 22:58:21 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/04 22:58:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_addv(
		t_mat4 self,
		t_vec3 other)
{
	self.inner[3][0] += other.x;
	self.inner[3][1] += other.y;
	self.inner[3][2] += other.z;
	return (self);
}
