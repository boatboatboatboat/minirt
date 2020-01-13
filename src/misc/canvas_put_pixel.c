/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 07:57:19 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 07:57:19 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

void	canvas_put_pixel(
		t_canvas *self,
		unsigned int x,
		unsigned int y,
		unsigned int color)
{
	t_size	offset;

	offset = y * self->size_line + x * (self->bits_per_pixel / 8);
	*(unsigned int *)(self->data + offset) = color;
}
