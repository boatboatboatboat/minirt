/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:26:24 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:52:38 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *byte_string, int value, t_size length)
{
	t_size	idx;

	idx = 0;
	while (idx < length)
	{
		((unsigned char *)byte_string)[idx] = (unsigned char)value;
		idx += 1;
	}
	return (byte_string);
}
