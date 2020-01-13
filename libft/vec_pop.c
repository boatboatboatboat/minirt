/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_pop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 20:13:31 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:51:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*vec_pop(t_vec *self)
{
	self->size -= 1;
	return (self->raw[self->size + 1]);
}
