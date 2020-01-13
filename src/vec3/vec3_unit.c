/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:56:02 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/19 16:59:43 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>

t_vec3	vec3_unit(t_vec3 self)
{
	t_f64		magnitude;
	t_vec3		out;

	magnitude = vec3_magnitude(self);
	out.x = self.x;
	out.y = self.y;
	out.z = self.z;
	if (magnitude > 0.0)
		return (vec3_divf(out, magnitude));
	return (out);
}
