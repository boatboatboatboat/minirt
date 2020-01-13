/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 01:18:47 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 10:19:09 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	rotate_right(t_draw_obj *drawer)
{
	t_camera	*camera;

	vector_getr(&drawer->scene->cameras,
				drawer->scene->current_camera, (void **)&camera);
	camera->adjust = vec3_add(
			camera->adjust, vec3_new(0, rad(CAM_ROT_SPEED), 0));
	drawer->last_action = "Rotated right";
}
