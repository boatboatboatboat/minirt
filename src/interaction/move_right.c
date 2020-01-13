/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 00:28:07 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 01:35:19 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>

void	move_right(t_draw_obj *drawer)
{
	t_mat4		rel;
	t_camera	*camera;

	vector_getr(&drawer->scene->cameras,
				drawer->scene->current_camera, (void **)&camera);
	rel = mat4_mul(mat4_angles(fmod(camera->adjust.x, M_PI * 2),
							fmod(camera->adjust.y, M_PI * 2),
							fmod(camera->adjust.z, M_PI * 2)), camera->cframe);
	camera->cframe = mat4_addv(camera->cframe, mat4_right_vec(rel));
	drawer->last_action = "Moved right";
}
