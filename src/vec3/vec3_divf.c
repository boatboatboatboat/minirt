/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_divf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:06:22 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 16:09:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3		vec3_divf(
		t_vec3 self,
		t_f64 other)
{
	t_vec3	out;

	out.x = self.x / other;
	out.y = self.y / other;
	out.z = self.z / other;
	return (out);
}
