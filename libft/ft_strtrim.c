/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 19:28:57 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/11 17:44:52 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s1, const char *set)
{
	t_size	start;
	t_size	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (s1[start] != '\0' && ft_isinset(s1[start], set))
		start += 1;
	while (ft_isinset(s1[end], set) && end > start)
		end -= 1;
	return (ft_substr(s1, start, end - start + 1));
}
