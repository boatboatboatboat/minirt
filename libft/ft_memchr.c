/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:05:28 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:52:38 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int occur, t_size length)
{
	unsigned char		*cast_string;
	unsigned char		cast_occur;
	t_size				index;

	cast_occur = (unsigned char)occur;
	cast_string = (unsigned char *)string;
	index = 0;
	while (index < length)
	{
		if (cast_string[index] == cast_occur)
			return (cast_string + index);
		index += 1;
	}
	return (NULL);
}
