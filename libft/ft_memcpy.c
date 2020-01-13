/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:43:30 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:17:04 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size length)
{
	t_size	idx;

	if (dest == src)
		return (dest);
	idx = 0;
	while (idx < length)
	{
		((unsigned char *)dest)[idx] = ((const unsigned char *)src)[idx];
		idx += 1;
	}
	return (dest);
}
