/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_shrink_to_fit.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:13:15 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:51:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		vec_shrink_to_fit(t_vec *self)
{
	return (vec_shrink(self, self->size));
}
