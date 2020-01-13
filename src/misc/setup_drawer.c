/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_drawer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 07:20:44 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 08:02:18 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

void	setup_canvas(
		t_draw_obj *drawer,
		t_scene *scene)
{
	drawer->current_canvas = 0;
	drawer->canvas1.img = mlx_new_image(drawer->mlx, scene->resolution[0],
										scene->resolution[1]);
	drawer->canvas2.img = mlx_new_image(drawer->mlx, scene->resolution[0],
										scene->resolution[1]);
	if (drawer->canvas1.img)
		drawer->canvas1.data = mlx_get_data_addr(drawer->canvas1.img,
				&drawer->canvas1.bits_per_pixel,
				&drawer->canvas1.size_line, &drawer->canvas1.endian);
	else
	{
		drawer_destroy(drawer);
		panic("failed to create a canvas", false);
	}
	if (drawer->canvas2.img)
		drawer->canvas2.data = mlx_get_data_addr(drawer->canvas2.img,
				&drawer->canvas2.bits_per_pixel,
				&drawer->canvas2.size_line, &drawer->canvas2.endian);
	else
	{
		drawer_destroy(drawer);
		panic("failed to create a canvas", false);
	}
}

void	setup_drawer(
		t_draw_obj *drawer,
		t_scene *scene)
{
	drawer->mlx = mlx_init();
	assert(drawer->mlx != NULL, "unable to initialize context", false);
	drawer->win = mlx_new_window(
			drawer->mlx, scene->resolution[0], scene->resolution[1], "minirt");
	if (drawer->win == NULL)
	{
		drawer_destroy(drawer);
		panic("failed to create a window", false);
	}
	setup_canvas(drawer, scene);
	drawer->update_draw = 0;
	drawer->update_key = 1;
	drawer->target = vec3_zero();
	drawer->window_gone = false;
	drawer->last_action = IS_BONUS ? "Start (BONUS)" : "Start";
}
