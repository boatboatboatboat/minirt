/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:23:27 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/07 17:24:00 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <scene.h>
# include <libft.h>

# define MAX_RES_X 5120
# define MAX_RES_Y 2880

# define RES_SET 0b1
# define AMB_SET 0b10
# define ALL_SET 0b11

t_scene	parse_from_file(const char *path);
t_bool	cb_scene(
		char **input,
		t_scene *out);
t_bool	expects(
		char **input,
		const char *expected);
t_bool	expectc(
		char **input,
		char expected);
t_bool	skip_atleast(
		char **input,
		char matcher,
		t_size times);
t_bool	cb_resolution(
		char **input,
		t_scene *scene);
t_bool	take_number(
		char **input,
		t_size *out);
t_bool	cb_color(
		char **input,
		t_color *color);
t_bool	cb_ambient(
		char **input,
		t_scene *scene);
t_bool	cb_camera(
		char **input,
		t_scene *scene);
t_bool	take_f64(
		char **input,
		t_f64 *out);
t_bool	cb_vector(
		char **input,
		t_vec3 *vec);
t_bool	cb_light(
		char **input,
		t_scene *scene);
t_bool	cb_sphere(
		char **input,
		t_scene *scene);
t_bool	cb_plane(
		char **input,
		t_scene *scene);
t_bool	cb_cylinder(
		char **input,
		t_scene *scene);
t_bool	cb_triangle(
		char **input,
		t_scene *scene);
t_bool	cb_square(
		char **input,
		t_scene *scene);

#endif
