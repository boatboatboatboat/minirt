/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:11:05 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:52:38 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, t_size length)
{
	const unsigned char	*cast_str1;
	const unsigned char	*cast_str2;
	t_size				index;

	index = 0;
	cast_str1 = str1;
	cast_str2 = str2;
	while (index < length)
	{
		if (cast_str1[index] != cast_str2[index])
			return (cast_str1[index] - cast_str2[index]);
		index += 1;
	}
	return (0);
}
