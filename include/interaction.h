/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 00:24:13 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/10 23:39:18 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTION_H
# define INTERACTION_H

# include <draw.h>

# define CAM_SPEED 0.5
# define CAM_ROT_SPEED 5.0
# define CAM_FOV_STEP 2.0
# define RESIZE_STEP 0.5
# define ROT_DEGREES 90.0
# define TRANSLATE_STEP 1.0

typedef enum	e_keycode
{
	Escape = 53,
	Q = 12,
	E = 14,
	W = 1,
	S = 13,
	A = 0,
	D = 2,
	Left = 123,
	Right = 124,
	Up = 125,
	Down = 126,
	Minus = 27,
	Plus = 24,
	Comma = 43,
	Dot = 47,
	PageUp = 116,
	PageDown = 121,
	NumPlus = 69,
	NumMinus = 78,
	AngleOpen = 33,
	AngleClose = 30,
	R = 15,
	T = 17,
	Y = 16,
	F = 3,
	G = 5,
	H = 4,
	U = 32,
	I = 34,
	O = 31,
	J = 38,
	K = 40,
	L = 37,
	None = -1
}				t_keycode;

typedef struct	s_key_pair
{
	t_keycode	keycode;
	void		(*action)(t_draw_obj *);
}				t_key_pair;

void			move_forward(t_draw_obj *drawer);
void			move_back(t_draw_obj *drawer);
void			move_left(t_draw_obj *drawer);
void			move_right(t_draw_obj *drawer);
void			move_up_world(t_draw_obj *drawer);
void			move_down_world(t_draw_obj *drawer);
void			increase_fov(t_draw_obj *drawer);
void			decrease_fov(t_draw_obj *drawer);
void			rotate_left(t_draw_obj *drawer);
void			rotate_right(t_draw_obj *drawer);
void			pitch_up(t_draw_obj *drawer);
void			pitch_down(t_draw_obj *drawer);
void			roll_left(t_draw_obj *drawer);
void			roll_right(t_draw_obj *drawer);
void			exit_program(t_draw_obj *drawer);
void			next_camera(t_draw_obj *drawer);
void			prev_camera(t_draw_obj *drawer);
void			increase_obj_size(t_draw_obj *drawer);
void			decrease_obj_size(t_draw_obj *drawer);
void			scale_up(t_draw_obj *drawer);
void			scale_down(t_draw_obj *drawer);
int				exit_program_i(t_draw_obj *drawer);
void			change_obj_pos(
		t_draw_obj *drawer,
		t_vec3 offset);
void			change_obj_rot(
		t_draw_obj *drawer,
		t_vec3 offset);
void			obj_pos_addx(t_draw_obj *drawer);
void			obj_pos_subx(t_draw_obj *drawer);
void			obj_pos_addy(t_draw_obj *drawer);
void			obj_pos_suby(t_draw_obj *drawer);
void			obj_pos_addz(t_draw_obj *drawer);
void			obj_pos_subz(t_draw_obj *drawer);
void			obj_rot_addx(t_draw_obj *drawer);
void			obj_rot_subx(t_draw_obj *drawer);
void			obj_rot_addy(t_draw_obj *drawer);
void			obj_rot_suby(t_draw_obj *drawer);
void			obj_rot_addz(t_draw_obj *drawer);
void			obj_rot_subz(t_draw_obj *drawer);

#endif
