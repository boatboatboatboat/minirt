/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:04:09 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 16:20:08 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_zero(void)
{
	t_vec3	zeroed;

	zeroed = vec3_zero();
	return (mat4_new(zeroed, zeroed, zeroed, zeroed));
}
