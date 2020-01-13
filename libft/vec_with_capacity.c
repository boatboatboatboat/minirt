/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_with_capacity.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:58:37 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 22:08:28 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	vec_with_capacity(t_vec *new, t_size capacity)
{
	new->capacity = capacity;
	new->size = 0;
	if (capacity == 0)
		new->raw = NULL;
	else
		new->raw = ft_calloc(capacity, sizeof(void *));
	if (capacity != 0 && new->raw == NULL)
		return (0);
	return (1);
}
