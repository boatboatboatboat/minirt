/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:28:33 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:45:26 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <dstring.h>
#include <parser.h>
#include <scene.h>
#include <stdlib.h>

static t_dstring	read_to_string(int fd)
{
	int			res;
	char		buffer[1025];
	t_dstring	string;

	res = 0;
	assert(dstring_new(&string), "string allocation failed", true);
	while (res > 0 || string.size == 0)
	{
		buffer[res] = '\0';
		if (dstring_push_str(&string, buffer) == false)
			panic("string allocation failed", true);
		res = read(fd, buffer, 1024);
		if (res <= 0)
			break ;
	}
	if (res == -1)
	{
		free(string.raw);
		panic("failed to read file", true);
	}
	return (string);
}

t_scene				parse_from_file(const char *path)
{
	int			fd;
	char		*worker;
	t_dstring	file;
	t_scene		out;

	fd = open(path, O_RDONLY);
	assert(fd != -1, "failed to open file", true);
	file = read_to_string(fd);
	assert(dstring_push_str(&file, "a"), "string allocation failed", true);
	file.raw[file.size - 1] = '\0';
	worker = file.raw;
	if (cb_scene(&worker, &out) == false || *worker != '\0')
	{
		free(file.raw);
		panic("unable to parse file", false);
	}
	free(file.raw);
	return (out);
}
