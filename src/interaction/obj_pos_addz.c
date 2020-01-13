/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_addz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 00:01:25 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/08 00:08:15 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	obj_pos_addz(t_draw_obj *drawer)
{
	change_obj_pos(drawer, vec3_new(0, 0, TRANSLATE_STEP));
}
