/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_subx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 00:01:25 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/08 00:02:17 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	obj_pos_subx(t_draw_obj *drawer)
{
	change_obj_pos(drawer, vec3_new(-TRANSLATE_STEP, 0, 0));
}
