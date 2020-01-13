/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:27:18 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/09 22:24:34 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	t_size			length;
	char			*out;

	if (s == NULL || f == NULL)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	out = ft_calloc(length + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	while (index < length)
	{
		out[index] = f(index, s[index]);
		index += 1;
	}
	out[index] = '\0';
	return (out);
}
