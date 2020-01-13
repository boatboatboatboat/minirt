/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:31:47 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:55:00 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>

t_bool	vector_resize(
		t_vector *self,
		t_size capacity)
{
	void	*new;

	if (capacity <= self->capacity)
		return (false);
	new = malloc(self->type_size * capacity);
	if (new == NULL)
		return (false);
	if (self->raw == NULL)
		self->raw = new;
	else
	{
		ft_memcpy(new, self->raw, self->size * self->type_size);
		free(self->raw);
		self->raw = new;
	}
	self->capacity = capacity;
	return (true);
}
