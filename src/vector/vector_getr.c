/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_getr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 23:02:12 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/04 23:03:56 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_getr(
		t_vector *self,
		t_size index,
		void **value)
{
	if (index >= self->size)
		return (false);
	*value = &(self->raw[self->type_size * index]);
	return (true);
}
