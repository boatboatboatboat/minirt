/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:13:06 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 19:13:49 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	cb_light(
		char **input,
		t_scene *scene)
{
	t_bool		result;
	t_light		light;

	result = (expectc(input, 'l')
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &light.position)
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &light.brightness)
			&& !(light.brightness < 0.0 || light.brightness > 1.0)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &light.color));
	if (result && !vector_push(&scene->lights, &light))
		return (false);
	return (result);
}
