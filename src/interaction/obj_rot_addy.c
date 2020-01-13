/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_addy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:03:21 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 21:03:21 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	obj_rot_addy(t_draw_obj *drawer)
{
	change_obj_rot(drawer, vec3_new(0, ROT_DEGREES, 0));
}
