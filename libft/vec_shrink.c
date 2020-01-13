/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_shrink.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:13:24 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:53:55 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		vec_shrink(t_vec *self, t_size capacity)
{
	void	**new_raw;

	if (capacity >= self->capacity)
		return (SUCCESS);
	self->capacity = capacity;
	new_raw = ft_calloc(capacity, sizeof(void *));
	if (new_raw == NULL)
		return (ERROR_MALLOC_FAILED);
	ft_memcpy(new_raw, self->raw, capacity * sizeof(void *));
	free(self->raw);
	self->raw = new_raw;
	return (SUCCESS);
}
