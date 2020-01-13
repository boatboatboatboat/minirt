/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:33:34 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:38:17 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_push(
		t_vector *self,
		void *value)
{
	t_size	min_capacity;

	min_capacity = self->capacity ? self->capacity : 1;
	if (self->size >= self->capacity)
		if (!vector_resize(self, min_capacity * 2))
			return (false);
	ft_memcpy(&self->raw[self->size * self->type_size],
			value, self->type_size);
	self->size += 1;
	return (true);
}
