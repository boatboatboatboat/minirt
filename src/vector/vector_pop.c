/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:37:37 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:42:26 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vector_pop(
		t_vector *self,
		void *output)
{
	t_bool	result;

	if (self->size == 0)
		return (false);
	result = vector_get(self, self->size - 1, output);
	if (result)
		self->size -= 1;
	return (result);
}
