/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:45:45 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 17:03:40 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <minirt.h>

typedef struct		s_vec3
{
	t_f64		x;
	t_f64		y;
	t_f64		z;
}					t_vec3;

t_vec3				vec3_new(t_f64 x, t_f64 y, t_f64 z);
t_vec3				vec3_zero(void);
t_f64				vec3_dot(t_vec3 self, t_vec3 other);
t_vec3				vec3_cross(t_vec3 self, t_vec3 other);
t_f64				vec3_norm(t_vec3 self);
t_f64				vec3_magnitude(t_vec3 self);
t_vec3				vec3_unit(t_vec3 self);
t_vec3				vec3_add(t_vec3 self, t_vec3 other);
t_vec3				vec3_sub(t_vec3 self, t_vec3 other);
t_vec3				vec3_mul(t_vec3 self, t_vec3 other);
t_vec3				vec3_div(t_vec3 self, t_vec3 other);
t_vec3				vec3_unm(t_vec3 self);
t_vec3				vec3_mulf(t_vec3 self, t_f64 other);
t_vec3				vec3_divf(t_vec3 self, t_f64 other);
t_vec3				vec3_forward(void);
t_vec3				vec3_up(void);
t_vec3				vec3_right(void);

extern const t_vec3	g_vec3_right;
extern const t_vec3	g_vec3_up;
extern const t_vec3	g_vec3_forward;

#endif
