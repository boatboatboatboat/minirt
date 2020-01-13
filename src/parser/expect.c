/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:49:07 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/21 21:02:24 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>

t_bool	expects(
		char **input,
		const char *expected)
{
	const t_size	length = ft_strlen(expected);
	const t_bool	result = ft_strncmp(*input, expected, length) == 0;

	if (result)
		*input += length;
	return (result);
}

t_bool	expectc(
		char **input,
		char expected)
{
	const t_bool result = **input == expected;

	*input += result;
	return (result);
}
