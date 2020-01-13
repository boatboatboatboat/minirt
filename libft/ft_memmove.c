/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:37:11 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/12 19:02:29 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size length)
{
	t_size	idx;

	if (length == 0 || dest == src)
		return (dest);
	idx = (dest < src) ? 0 : length;
	if (dest < src)
		ft_memcpy(dest, src, length);
	else
		while (idx > 0)
		{
			idx -= 1;
			((unsigned char *)dest)[idx] = ((const unsigned char *)src)[idx];
		}
	return (dest);
}
