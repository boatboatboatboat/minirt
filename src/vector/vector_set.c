/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:36:20 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:38:17 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_set(
		t_vector *self,
		t_size index,
		void *value)
{
	if (index > self->capacity)
		return (false);
	ft_memcpy(&(self->raw[self->type_size * index]), value, self->type_size);
	return (true);
}
