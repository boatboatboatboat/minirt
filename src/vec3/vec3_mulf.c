/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mulf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:04:18 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 15:50:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3	vec3_mulf(
		t_vec3 self,
		t_f64 other)
{
	t_vec3	out;

	out.x = self.x * other;
	out.y = self.y * other;
	out.z = self.z * other;
	return (out);
}
