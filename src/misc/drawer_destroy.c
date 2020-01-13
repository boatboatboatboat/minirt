/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 02:17:14 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 02:21:53 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <draw.h>

void	drawer_destroy(t_draw_obj *drawer)
{
	if (!drawer->window_gone && drawer->win)
		mlx_destroy_window(drawer->mlx, drawer->win);
	if (drawer->canvas1.img)
		mlx_destroy_image(drawer->mlx, drawer->canvas1.img);
	if (drawer->canvas2.img)
		mlx_destroy_image(drawer->mlx, drawer->canvas2.img);
	vector_destroy(&drawer->scene->objects);
	vector_destroy(&drawer->scene->lights);
	vector_destroy(&drawer->scene->cameras);
	vector_destroy(&drawer->scene->buffer);
}
