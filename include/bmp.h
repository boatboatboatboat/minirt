/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:24:12 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 08:48:36 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <minirt.h>
# include <vector.h>

typedef struct	s_bmp_file_header
{
	t_u32	file_size;
	t_u32	pixel_data_offset;
}				t_bmp_file_header;

typedef struct	s_bmp_info_header
{
	t_u32		header_size;
	t_i32		image_width;
	t_i32		image_height;
	t_u16		bits_per_pixel;
	t_u32		total_colors;
}				t_bmp_info_header;

t_bool			output_bmp(
		t_vector *colors,
		unsigned int width,
		unsigned int height);

#endif
