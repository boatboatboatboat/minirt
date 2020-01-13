/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_subz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:04:15 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 23:36:55 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	obj_rot_subz(t_draw_obj *drawer)
{
	if (drawer->selection != NULL && drawer->selection->tag == Square)
		return ;
	change_obj_rot(drawer, vec3_new(0, 0, -ROT_DEGREES));
}
