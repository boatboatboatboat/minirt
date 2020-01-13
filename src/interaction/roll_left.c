/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:41:01 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 05:41:01 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	roll_left(t_draw_obj *drawer)
{
	t_camera	*camera;

	vector_getr(&drawer->scene->cameras,
				drawer->scene->current_camera, (void **)&camera);
	camera->adjust = vec3_sub(
			camera->adjust, vec3_new(0, 0, rad(CAM_ROT_SPEED)));
	drawer->last_action = "Rolled left";
}
