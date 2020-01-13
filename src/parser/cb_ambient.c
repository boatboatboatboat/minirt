/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_ambient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:15:55 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/04 19:53:42 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool	cb_ambient(
		char **input,
		t_scene *scene)
{
	if (scene->set & AMB_SET)
		return (false);
	scene->set |= AMB_SET;
	return (expectc(input, 'A')
			&& skip_atleast(input, ' ', 1)
			&& take_f64(input, &scene->ambient_brightness)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &scene->ambient_color));
}
