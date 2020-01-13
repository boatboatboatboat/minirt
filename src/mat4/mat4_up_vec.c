/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_up_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:27:30 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 23:27:30 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_vec3		mat4_up_vec(t_mat4 self)
{
	return (vec3_unit(vec3_new(self.inner[1][0],
			self.inner[1][1],
			self.inner[1][2])));
}
