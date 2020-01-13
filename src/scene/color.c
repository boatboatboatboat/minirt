/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:46:06 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 23:47:23 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

static unsigned char	sat_add(
		unsigned char a,
		unsigned char b)
{
	unsigned char c;

	c = a + b;
	if (c < a)
		c = -1;
	return (c);
}

unsigned int			color_as_uint(t_color color)
{
	unsigned int	out;

	out = color.r;
	out = (out << 8) + color.g;
	out = (out << 8) + color.b;
	return (out);
}

t_color					color_add(
		t_color a,
		t_color b)
{
	t_color	out;

	out.r = sat_add(a.r, b.r);
	out.g = sat_add(a.g, b.g);
	out.b = sat_add(a.b, b.b);
	return (out);
}

t_color					color_mul(
		t_color a,
		t_color b,
		t_f64 mult)
{
	t_color	out;

	out.r = (t_u8)((t_f64)a.r * (t_f64)b.r * mult / 255.0);
	out.g = (t_u8)((t_f64)a.g * (t_f64)b.g * mult / 255.0);
	out.b = (t_u8)((t_f64)a.b * (t_f64)b.b * mult / 255.0);
	return (out);
}

t_color					color_new(
		t_u8 r,
		t_u8 g,
		t_u8 b)
{
	t_color	out;

	out.r = r;
	out.g = g;
	out.b = b;
	return (out);
}
