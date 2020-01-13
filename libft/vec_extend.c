/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_extend.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:04:11 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:32:27 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	vec_extend(t_vec *self, t_size delta)
{
	void	**old_raw;

	old_raw = self->raw;
	self->capacity += delta;
	self->raw = ft_calloc(self->capacity, sizeof(void *));
	if (self->raw == NULL)
		return (ERROR_MALLOC_FAILED);
	if (old_raw)
		ft_memcpy(self->raw, old_raw, self->size * sizeof(void *));
	free(old_raw);
	return (SUCCESS);
}
