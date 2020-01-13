/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:18:24 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:52:38 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size		ft_strlen(const char *str)
{
	t_size	length;

	length = 0;
	while (str[length] != 0)
		length += 1;
	return (length);
}
