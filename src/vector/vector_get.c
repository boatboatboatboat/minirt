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

t_bool	vector_get(
		t_vector *self,
		t_size index,
		void *value)
{
	if (index >= self->size)
		return (false);
	ft_memcpy(value, &(self->raw[self->type_size * index]), self->type_size);
	return (true);
}
