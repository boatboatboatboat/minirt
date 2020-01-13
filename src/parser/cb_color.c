/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:21:07 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 23:05:22 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <scene.h>

t_bool			cb_color(
		char **input,
		t_color *color)
{
	t_size	tmp;

	if (take_number(input, &tmp) && tmp <= 255)
		color->r = (unsigned char)tmp;
	else
		return (false);
	if (expectc(input, ',') && take_number(input, &tmp) && tmp <= 255)
		color->g = (unsigned char)tmp;
	else
		return (false);
	if (expectc(input, ',') && take_number(input, &tmp) && tmp <= 255)
		color->b = (unsigned char)tmp;
	else
		return (false);
	return (true);
}
