/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:48:59 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/12 20:29:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, t_size len)
{
	t_size	idx;
	t_size	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	idx = 0;
	while (haystack[idx] != '\0' && (idx + needle_len) <= len)
	{
		if (ft_strncmp(haystack + idx, needle, needle_len) == 0)
			return ((char *)(haystack + idx));
		idx += 1;
	}
	return (NULL);
}
