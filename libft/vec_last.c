/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_last.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 20:24:39 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:51:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*vec_last(t_vec *self)
{
	return (self->raw[self->size - 1]);
}
