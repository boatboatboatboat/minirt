/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 01:04:29 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 01:04:29 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_mul(
		t_mat4 self,
		t_mat4 other)
{
	t_mat4	out;
	t_size	i;
	t_size	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out.inner[i][j] = self.inner[i][0] * other.inner[0][j] +
					self.inner[i][1] * other.inner[1][j] +
					self.inner[i][2] * other.inner[2][j] +
					self.inner[i][3] * other.inner[3][j];
			j += 1;
		}
		i += 1;
	}
	return (out);
}
