/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:31:28 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:21:35 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcat(char *dest, const char *src, t_size dstsize)
{
	t_size	dest_len;
	t_size	count;

	dest_len = ft_strlen(dest);
	count = 0;
	if (dstsize <= dest_len)
		return (ft_strlen(src) + dstsize);
	dest += dest_len;
	while (src[count] != 0)
	{
		if (count == (dstsize - dest_len - 1))
			break ;
		dest[count] = src[count];
		count += 1;
	}
	dest[count] = '\0';
	return (ft_strlen(src) + dest_len);
}
