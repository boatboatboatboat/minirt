/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:49:18 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/09 22:37:27 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	t_size	len1;
	t_size	len2;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (joined == NULL)
		return (NULL);
	(void)ft_memcpy(joined, s1, len1);
	(void)ft_memcpy(joined + len1, s2, len2);
	return (joined);
}
