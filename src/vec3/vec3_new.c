/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:58:27 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/19 16:01:11 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3		vec3_new(t_f64 x, t_f64 y, t_f64 z)
{
	t_vec3	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}