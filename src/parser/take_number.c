/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:47:10 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 20:26:33 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <parser.h>

t_bool		take_number(
		char **input,
		t_size *out)
{
	t_size		res;

	res = 0;
	if (!ft_isdigit(**input))
		return (false);
	while (ft_isdigit(**input))
	{
		res = res * 10 + (**input - '0') % 10;
		*input += 1;
	}
	*out = res;
	return (true);
}
