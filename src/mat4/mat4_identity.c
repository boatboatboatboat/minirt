/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:38:48 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 16:47:03 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mat4.h>

t_mat4	mat4_identity(void)
{
	t_vec3	zeroed;

	zeroed = vec3_zero();
	return (mat4_new(g_vec3_right, g_vec3_up, g_vec3_forward, zeroed));
}
