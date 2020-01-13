/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:05:57 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 06:11:30 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

typedef struct	s_cylinder_helper
{
	t_vec3	p;
	t_vec3	v;
	t_vec3	pa;
	t_vec3	va;
	t_vec3	dp;
	t_vec3	common1;
	t_vec3	common2;
	t_f64	abc[3];
	t_vec3	p1;
	t_vec3	p2;
}				t_cylinder_helper;

typedef struct	s_square_helper
{
	t_mat4		local;
	t_vec3		upv;
	t_vec3		rgv;
	t_vec3		pa;
	t_vec3		pb;
	t_vec3		pc;
	t_vec3		pd;
}				t_square_helper;

#endif
