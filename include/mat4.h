/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:08:22 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 05:55:00 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# include <vec3.h>

typedef struct	s_mat4 {
	t_f64		inner[4][4];
}				t_mat4;

t_mat4			mat4_zero(void);
t_mat4			mat4_identity(void);
t_mat4			mat4_new(
		t_vec3 right,
		t_vec3 up,
		t_vec3 look,
		t_vec3 pos);
t_vec3			mat4_pos(t_mat4 self);
t_mat4			mat4_angles(t_f64 x, t_f64 y, t_f64 z);
t_mat4			mat4_lookat(
		t_vec3 position,
		t_vec3 target);
t_mat4			mat4_from_vec3(t_vec3 position);
t_mat4			mat4_mul(
		t_mat4 self,
		t_mat4 other);
t_mat4			mat4_mul_rbx(
		t_mat4 self,
		t_vec3 other);
t_vec3			mat4_look_vec(t_mat4 self);
t_vec3			mat4_right_vec(t_mat4 self);
t_vec3			mat4_up_vec(t_mat4 self);
t_vec3			mat4_mulv_dir(
		t_mat4 self,
		t_vec3 dir);
t_mat4			mat4_inverse(t_mat4 self);
t_mat4			mat4_addv(
		t_mat4 self,
		t_vec3 other);
t_mat4			mat4_angles(
		t_f64 x,
		t_f64 y,
		t_f64 z);
t_mat4			mat4_mul(
		t_mat4 self,
		t_mat4 other);

#endif
