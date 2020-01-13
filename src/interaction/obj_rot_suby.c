/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_suby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:03:41 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 21:03:41 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	obj_rot_suby(t_draw_obj *drawer)
{
	change_obj_rot(drawer, vec3_new(0, -ROT_DEGREES, 0));
}
