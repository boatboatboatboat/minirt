/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_cast_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:17:45 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/04 21:35:56 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_bool	scene_cast_ray(
		t_scene *self,
		const t_ray *ray,
		t_renderable **hit,
		t_f64 *distance)
{
	t_f64			tmp;
	t_renderable	*obj;
	t_size			idx;
	t_bool			found;

	idx = 0;
	found = false;
	*distance = NAN;
	while (idx < self->objects.size)
	{
		vector_getr(&self->objects, idx, (void **)&obj);
		if (obj->intersect(obj, ray, &tmp) && (!found || *distance > tmp))
		{
			*distance = tmp;
			if (hit != NULL)
				*hit = obj;
			found = true;
		}
		idx += 1;
	}
	return (found);
}
