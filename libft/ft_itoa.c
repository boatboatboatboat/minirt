/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:11:37 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/09 22:58:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(int n)
{
	int	tens;

	if (n == 0)
		return (1);
	tens = n < 0;
	while (n != 0)
	{
		n /= 10;
		tens += 1;
	}
	return (tens);
}

char		*ft_itoa(int n)
{
	char			*out;
	t_size			head;
	unsigned int	real_n;

	out = ft_calloc(number_length(n) + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	head = number_length(n);
	out[0] = (n < 0) ? '-' : '0';
	out[head] = '\0';
	real_n = (n > 0) ? (unsigned int)n : (unsigned int)-n;
	while (real_n != 0)
	{
		head -= 1;
		out[head] = real_n % 10 + '0';
		real_n /= 10;
	}
	return (out);
}
