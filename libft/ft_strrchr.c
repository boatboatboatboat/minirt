/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:43:16 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/09 21:45:21 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	cast_occur;
	t_size	index;

	index = ft_strlen(str) + 1;
	cast_occur = (char)chr;
	while (index > 0)
	{
		index -= 1;
		if (str[index] == cast_occur)
			return ((char *)(str + index));
	}
	return (NULL);
}
