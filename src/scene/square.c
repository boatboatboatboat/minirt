/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:03:42 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/07 15:18:04 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>
#include <helper.h>

static void		setup_helper(
		t_square *sq,
		t_square_helper *helper)
{
	helper->local = mat4_lookat(sq->center, vec3_add(sq->center, sq->rotation));
	helper->upv = vec3_mulf(mat4_up_vec(helper->local), sq->size);
	helper->rgv = vec3_mulf(mat4_right_vec(helper->local), sq->size);
	helper->pa = vec3_add(vec3_sub(sq->center, helper->upv), helper->rgv);
	helper->pb = vec3_add(vec3_add(sq->center, helper->upv), helper->rgv);
	helper->pc = vec3_sub(vec3_add(sq->center, helper->upv), helper->rgv);
	helper->pd = vec3_sub(vec3_sub(sq->center, helper->upv), helper->rgv);
}

t_bool			square_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_square_helper	helper;
	t_triangle		tri[2];
	t_f64			res[2];
	t_f64			hits[2];

	setup_helper(&self->var.square, &helper);
	tri[0].v0 = helper.pa;
	tri[0].v1 = helper.pb;
	tri[0].v2 = helper.pc;
	tri[1].v0 = helper.pa;
	tri[1].v1 = helper.pd;
	tri[1].v2 = helper.pc;
	hits[0] = real_triangle_intersect(&tri[0], ray, &res[0]);
	hits[1] = real_triangle_intersect(&tri[1], ray, &res[1]);
	if (hits[0] && hits[1])
		*out = fmin(res[0], res[1]);
	else if (hits[0])
		*out = res[0];
	else if (hits[1])
		*out = res[1];
	return (hits[0] || hits[1]);
}

t_vec3			square_normal(
		struct s_renderable *self,
		t_vec3 *hit)
{
	(void)hit;
	return (self->var.plane.rotation);
}
