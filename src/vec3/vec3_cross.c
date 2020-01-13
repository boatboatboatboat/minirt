/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:24:29 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 15:51:27 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3		vec3_cross(
		t_vec3 self,
		t_vec3 other)
{
	t_vec3	out;

	out.x = self.y * other.z - self.z * other.y;
	out.y = self.z * other.x - self.x * other.z;
	out.z = self.x * other.y - self.y * other.x;
	return (out);
}
