/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:15:40 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 21:16:23 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_ray	ray_new(
		t_vec3 origin,
		t_vec3 direction)
{
	t_ray	out;

	out.direction = direction;
	out.origin = origin;
	return (out);
}
