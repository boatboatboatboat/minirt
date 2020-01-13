/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:49:39 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 07:57:40 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <scene.h>
# include <libft.h>

typedef struct	s_canvas
{
	void			*img;
	char			*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_canvas;

typedef struct	s_draw_obj
{
	void			*mlx;
	void			*win;
	t_canvas		canvas1;
	t_canvas		canvas2;
	char			current_canvas;
	t_size			update_key;
	t_size			update_draw;
	t_scene			*scene;
	t_bool			window_gone;
	t_renderable	*selection;
	t_vec3			target;
	char			*last_action;
}				t_draw_obj;

void			drawer_destroy(t_draw_obj *drawer);
void			setup_drawer(
		t_draw_obj *drawer,
		t_scene *scene);
void			canvas_put_pixel(
		t_canvas *self,
		unsigned int x,
		unsigned int y,
		unsigned int color);

#endif
