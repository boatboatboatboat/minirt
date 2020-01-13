/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 09:33:02 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 09:33:02 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_inverse(t_mat4 self)
{
	t_mat4	out;
	t_size	x;
	t_size	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			out.inner[x][y] = self.inner[y][x];
			y += 1;
		}
		x += 1;
	}
	return (out);
}
