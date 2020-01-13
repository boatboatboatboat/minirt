/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 01:56:10 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 02:05:35 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_bool	solve_quad(
		t_f64 abc[3],
		t_f64 x[2])
{
	t_f64	discriminant;

	discriminant = pow(abc[1], 2) - 4.0 * abc[0] * abc[2];
	if (discriminant < 0.0)
		return (false);
	else if (discriminant < EPSILON)
	{
		x[0] = -0.5 * abc[1] / abc[0];
		x[1] = x[0];
	}
	else
	{
		x[0] = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
		x[1] = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
	}
	return (true);
}
