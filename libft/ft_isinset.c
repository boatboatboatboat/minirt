/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isinset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:31:45 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/11 17:43:36 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinset(char c, const char *set)
{
	t_size	idx;

	idx = 0;
	while (set[idx] != c && set[idx] != '\0')
		idx += 1;
	return (set[idx] == c);
}
