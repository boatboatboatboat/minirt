/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 00:37:58 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 00:37:58 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void	move_down_world(t_draw_obj *drawer)
{
	t_camera	*camera;

	vector_getr(&drawer->scene->cameras,
				drawer->scene->current_camera, (void **)&camera);
	camera->cframe = mat4_addv(camera->cframe, vec3_new(0, -CAM_SPEED, 0));
	drawer->last_action = "Moved down on world axis";
}
