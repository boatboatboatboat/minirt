/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:55:49 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/07 17:28:37 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	cb_resolution(
		char **input,
		t_scene *scene)
{
	t_bool	result;

	if (scene->set & RES_SET)
		return (false);
	result = (expectc(input, 'R')
			&& skip_atleast(input, ' ', 1)
			&& take_number(input, &(scene->resolution[0]))
			&& scene->resolution[0] > 0
			&& skip_atleast(input, ' ', 1)
			&& take_number(input, &(scene->resolution[1]))
			&& scene->resolution[1] > 0);
	if (result)
	{
		scene->set |= RES_SET;
		if (scene->resolution[0] > MAX_RES_X)
			scene->resolution[0] = MAX_RES_X;
		if (scene->resolution[1] > MAX_RES_Y)
			scene->resolution[1] = MAX_RES_Y;
	}
	return (result);
}
