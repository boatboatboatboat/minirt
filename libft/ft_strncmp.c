/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:38:20 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/12 20:10:14 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, t_size length)
{
	t_size	index;

	index = 0;
	while (index < length)
	{
		if (str1[index] == '\0' || str1[index] != str2[index])
			break ;
		index += 1;
	}
	if (index == length)
		return (0);
	else
		return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
