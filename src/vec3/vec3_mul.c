/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:01:53 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 15:50:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3		vec3_mul(
		t_vec3 self,
		t_vec3 other)
{
	t_vec3	out;

	out.x = self.x * other.x;
	out.y = self.y * other.y;
	out.z = self.z * other.z;
	return (out);
}
