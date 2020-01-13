/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:44:43 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/09 22:33:27 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(const char *s, unsigned int start, t_size len)
{
	char	*sub;
	t_size	idx;
	t_size	max;

	if (s == NULL)
		return (NULL);
	max = ft_strlen(s);
	if (start >= max)
		return (ft_strdup(""));
	if (len > (max - start))
		len = max - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	idx = 0;
	while (idx < len && (start + idx) <= max)
	{
		sub[idx] = s[start + idx];
		idx += 1;
	}
	return (sub);
}
