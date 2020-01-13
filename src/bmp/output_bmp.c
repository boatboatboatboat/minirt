/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:54:05 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 23:42:27 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bmp.h>
#include <minirt.h>
#include <fcntl.h>
#include <unistd.h>
#include <scene.h>

t_bool	output_bmp(
		t_vector *colors,
		unsigned int width,
		unsigned int height)
{
	static const int	zeroed[32];
	int					fd;
	t_size				idx;
	t_color				*color;

	fd = open("output.bmp", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (false);
	write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, "\x01\x00\x18\x00", 4);
	write(fd, zeroed, 24);
	idx = height;
	while (idx > 0)
	{
		idx -= 1;
		(void)vector_getr(colors, idx * width, (void **)&color);
		write(fd, color, width * sizeof(t_color));
	}
	return (true);
}
