/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:08:34 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:51:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	output;
	t_size			idx;
	int				sign;

	sign = 0;
	output = 0;
	idx = 0;
	while (ft_isspace(str[idx]))
		idx += 1;
	if (str[idx] == '-')
		sign = 1;
	idx += str[idx] == '+' || str[idx] == '-';
	while (ft_isdigit(str[idx]))
	{
		output = (output * 10) + str[idx] - '0';
		idx += 1;
	}
	if (sign && (output >= (unsigned)(LONG_MAX - 1)))
		return (0);
	else if (output >= (unsigned)LONG_MAX)
		return (-1);
	return ((int)(sign ? -output : output));
}
