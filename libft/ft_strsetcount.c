/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsetcount.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:22:24 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:52:38 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size		ft_strsetcount(const char *str, const char *set)
{
	t_size	count;
	t_size	set_idx;
	t_size	str_idx;

	count = 0;
	set_idx = 0;
	str_idx = 0;
	while (str[str_idx] != 0)
	{
		while (str[str_idx] != set[set_idx] && set_idx < ft_strlen(set))
			set_idx += 1;
		if (str[str_idx] != set[set_idx])
			count += 1;
		set_idx = 0;
		str_idx += 1;
	}
	return (count);
}
