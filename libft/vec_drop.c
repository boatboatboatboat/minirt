/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_drop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:39:14 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/05 21:22:39 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*vec_drop(t_vec *self, void (*del)(void *))
{
	t_size	idx;

	idx = 0;
	while (idx < self->size)
	{
		if (del == NULL)
			free(self->raw[idx]);
		else
			del(self->raw[idx]);
		idx += 1;
	}
	free(self->raw);
	free(self);
	return (NULL);
}
