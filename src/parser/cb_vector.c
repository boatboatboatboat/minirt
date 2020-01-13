/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:00:21 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 23:04:03 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <scene.h>

t_bool			cb_vector(
		char **input,
		t_vec3 *vec)
{
	return (take_f64(input, &vec->x)
		&& expectc(input, ',')
		&& take_f64(input, &vec->y)
		&& expectc(input, ',')
		&& take_f64(input, &vec->z));
}
