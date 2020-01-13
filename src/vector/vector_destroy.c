/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:29:02 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 18:31:49 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdlib.h>

void	vector_destroy(t_vector *self)
{
	free(self->raw);
	self->raw = NULL;
	self->capacity = 0;
	self->size = 0;
	self->type_size = 0;
}
