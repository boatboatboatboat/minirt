/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:34:46 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/05 19:38:34 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	t_size	len;

	len = ft_strlen(str) + 1;
	dup = ft_calloc(len, sizeof(char));
	if (dup == NULL)
		return (NULL);
	return (ft_memcpy(dup, str, len));
}
