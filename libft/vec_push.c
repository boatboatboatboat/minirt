/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:02:04 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:59:48 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		vec_push(t_vec *self, void *item)
{
	int res;

	res = 0;
	if (self->capacity == 0)
		res = vec_extend(self, 4);
	if (res != SUCCESS)
		return (res);
	if (self->size >= self->capacity)
		res = vec_extend(self, self->capacity);
	if (res != SUCCESS)
		return (res);
	self->raw[self->size] = item;
	self->size += 1;
	return (SUCCESS);
}
