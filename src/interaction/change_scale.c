/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 06:40:49 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 10:20:57 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	scale_up(t_draw_obj *drawer)
{
	drawer->scene->scale += 1;
	drawer->last_action = "Increased SSAA";
	if (drawer->scene->scale == 2)
		drawer->last_action = "Enabled SSAA";
}

void	scale_down(t_draw_obj *drawer)
{
	drawer->scene->scale -= 1;
	drawer->last_action = "Decreased SSAA";
	if (drawer->scene->scale < 2)
	{
		drawer->scene->scale = 1;
		drawer->last_action = "Disabled SSAA";
	}
}
