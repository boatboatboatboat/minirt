/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_get.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 21:13:21 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:51:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*vec_get(t_vec *self, t_size index)
{
	return (self->raw[index]);
}
