/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 02:27:04 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 02:27:04 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	prev_camera(t_draw_obj *drawer)
{
	drawer->scene->current_camera =
			(drawer->scene->current_camera - 1) % drawer->scene->cameras.size;
	drawer->last_action = "Switched to previous camera";
}
