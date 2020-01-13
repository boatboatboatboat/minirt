/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:59:22 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 23:37:11 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <scene.h>
#include <parser.h>
#include <mlx.h>
#include <draw.h>
#include <interaction.h>
#include <bmp.h>

const t_key_pair	g_interactions[] =
{
	{Escape, exit_program},
	{Q, move_down_world},
	{E, move_up_world},
	{W, move_forward},
	{S, move_back},
	{A, move_left},
	{D, move_right},
	{Left, rotate_left},
	{Right, rotate_right},
	{Up, pitch_up},
	{Down, pitch_down},
	{Plus, increase_fov},
	{Minus, decrease_fov},
	{Comma, roll_left},
	{Dot, roll_right},
	{PageUp, next_camera},
	{PageDown, prev_camera},
	{NumPlus, increase_obj_size},
	{NumMinus, decrease_obj_size},
	{AngleOpen, scale_up},
	{AngleClose, scale_down},
	{R, obj_pos_suby},
	{Y, obj_pos_addy},
	{T, obj_pos_addz},
	{G, obj_pos_subz},
	{F, obj_pos_subx},
	{H, obj_pos_addx},
	{J, obj_rot_suby},
	{L, obj_rot_addy},
	{U, obj_rot_addz},
	{O, obj_rot_subz},
	{I, obj_rot_subx},
	{K, obj_rot_addx},
	{-1, NULL}
};

int		draw(t_draw_obj *drawer)
{
	t_size		pixel;
	t_color		color;
	t_canvas	canvas;

	if (drawer->update_draw < drawer->update_key)
	{
		pixel = 0;
		canvas = drawer->current_canvas ? drawer->canvas1 : drawer->canvas2;
		scene_render(drawer->scene);
		while (pixel < drawer->scene->buffer.size)
		{
			vector_get(&drawer->scene->buffer, pixel, &color);
			canvas_put_pixel(&canvas, pixel % drawer->scene->resolution[0],
					pixel / (drawer->scene->resolution[0]),
					color_as_uint(color));
			pixel += 1;
		}
		drawer->current_canvas = (char)!drawer->current_canvas;
		mlx_put_image_to_window(drawer->mlx, drawer->win, canvas.img, 0, 0);
		mlx_string_put(drawer->mlx, drawer->win, 0, 10, 0x00FFFFFF,
				drawer->last_action);
		drawer->update_draw += 1;
	}
	return (0);
}

int		key_handle(
		int keycode,
		t_draw_obj *drawer)
{
	t_size	idx;

	idx = 0;
	while (g_interactions[idx].action != NULL)
	{
		if (g_interactions[idx].keycode == keycode)
			g_interactions[idx].action(drawer);
		idx += 1;
	}
	drawer->update_key += 1;
	return (0);
}

int		mouse_handle(
		int button,
		int x,
		int y,
		t_draw_obj *drawer)
{
	t_ray			ray;
	t_f64			distance;
	t_camera		*cur;
	t_scene			*scene;
	t_renderable	*select;

	scene = drawer->scene;
	vector_getr(&scene->cameras, scene->current_camera, (void **)&cur);
	ray = screen_ray(scene, x, y);
	select = NULL;
	if (button != 3 && button != 1)
		return (false);
	if (scene_cast_ray(scene, &ray, &select, &distance))
	{
		cur->adjust = button == 3 ? vec3_zero() : cur->adjust;
		if (button == 3)
			cur->cframe = mat4_lookat(mat4_pos(cur->cframe), \
					vec3_add(ray.origin, vec3_mulf(ray.direction, distance)));
	}
	drawer->selection = button == 1 ? select : drawer->selection;
	drawer->last_action = button == 3 ? "Looking at" : "Selected object";
	drawer->update_key += 1;
	return (0);
}

void	start_mlx(t_draw_obj *drawer)
{
	mlx_loop_hook(drawer->mlx, draw, drawer);
	mlx_mouse_hook(drawer->win, mouse_handle, drawer);
	mlx_key_hook(drawer->win, key_handle, drawer);
	mlx_hook(drawer->win, 17, (1L << 17), exit_program_i, drawer);
	mlx_loop(drawer->mlx);
}

int		main(int argc, char **argv)
{
	t_scene		scene;
	t_draw_obj	drawer;

	if (argc < 2)
		panic("no file has been provided", false);
	if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 3]), ".rt", 4) != 0)
		panic("the provided file has an invalid extension", false);
	scene = parse_from_file(argv[1]);
	ft_bzero(&drawer, sizeof(drawer));
	drawer.scene = &scene;
	if (argc >= 3 && ft_strncmp(argv[2], "--save", 6) == 0)
	{
		scene_render(&scene);
		if (!output_bmp(&scene.buffer, scene.resolution[0],
				scene.resolution[1]))
		{
			drawer_destroy(&drawer);
			panic("failed to output bmp", false);
		}
		drawer_destroy(&drawer);
		return (0);
	}
	setup_drawer(&drawer, &scene);
	start_mlx(&drawer);
	return (0);
}
