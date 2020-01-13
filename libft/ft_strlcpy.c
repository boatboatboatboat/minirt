/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:19:49 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:30:05 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size		ft_strlcpy(char *dest, const char *src, t_size dstsize)
{
	t_size	len;
	t_size	src_len;

	if (dest == NULL && src == NULL)
		return (0);
	src_len = ft_strlen(src);
	if (dest == src)
		return (src_len);
	len = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[len] != 0 && len < (dstsize - 1))
	{
		dest[len] = src[len];
		len += 1;
	}
	dest[len] = '\0';
	return (src_len);
}
