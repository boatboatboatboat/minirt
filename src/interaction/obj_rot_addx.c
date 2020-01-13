/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_addx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:01:22 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 21:01:22 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	obj_rot_addx(t_draw_obj *drawer)
{
	change_obj_rot(drawer, vec3_new(ROT_DEGREES, 0, 0));
}
