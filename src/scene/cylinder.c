/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 01:53:23 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 01:27:05 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <helper.h>
#include <math.h>

static t_cylinder_helper	calc_vars(
		t_cylinder *cyl,
		const t_ray *ray)
{
	t_cylinder_helper	vars;

	vars.p = ray->origin;
	vars.v = ray->direction;
	vars.pa = cyl->center;
	vars.va = cyl->rotation;
	vars.dp = vec3_sub(vars.p, vars.pa);
	vars.common1 =
			vec3_sub(vars.v, vec3_mulf(vars.va, vec3_dot(vars.v, vars.va)));
	vars.common2 =
			vec3_sub(vars.dp, vec3_mulf(vars.va, vec3_dot(vars.dp, vars.va)));
	vars.abc[0] = vec3_norm(vars.common1);
	vars.abc[1] = 2.0 * vec3_dot(vars.common1, vars.common2);
	vars.abc[2] = vec3_norm(vars.common2) - pow(cyl->radius, 2);
	vars.p1 = vec3_sub(vars.pa, vec3_mulf(vars.va, cyl->height / 2.0));
	vars.p2 = vec3_add(vars.pa, vec3_mulf(vars.va, cyl->height / 2.0));
	return (vars);
}

static t_bool				real_intersect(
		t_cylinder *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_cylinder_helper	helper;
	t_f64				t[3];
	t_vec3				q;
	t_f64				res;

	helper = calc_vars(self, ray);
	res = -1;
	if (solve_quad(helper.abc, t))
	{
		q = vec3_add(helper.p, vec3_mulf(helper.v, t[0]));
		if (t[0] > 0.0 && vec3_dot(helper.va, vec3_sub(q, helper.p1)) > 0.0 \
			&& vec3_dot(helper.va, vec3_sub(q, helper.p2)) < 0.0)
			res = t[0];
		q = vec3_add(helper.p, vec3_mulf(helper.v, t[1]));
		if (t[1] > 0.0 && vec3_dot(helper.va, vec3_sub(q, helper.p1)) > 0.0 \
			&& vec3_dot(helper.va, vec3_sub(q, helper.p2)) < 0.0)
			res = res != -1 ? fmin(t[0], t[1]) : t[1];
	}
	if (res != -1)
		*out = res;
	return (res != -1);
}

t_bool						cylinder_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out)
{
	t_cylinder	*outer;

	outer = &self->var.cylinder;
	return (real_intersect(outer, ray, out));
}

t_vec3						cylinder_normal(
		struct s_renderable *self,
		t_vec3 *hit)
{
	t_cylinder *cyl;

	cyl = &self->var.cylinder;
	if (cyl->direction)
		return (vec3_unit(vec3_sub(*hit, cyl->center)));
	else
		return (vec3_unm(vec3_unit(vec3_sub(*hit, cyl->center))));
}
