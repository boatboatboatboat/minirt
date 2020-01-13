/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_f64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:56:59 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 19:05:45 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

static void		take_numberf(
		char **input,
		t_f64 *out)
{
	while (ft_isdigit(**input))
	{
		*out = *out * 10.0 + (**input - '0') % 10;
		*input += 1;
	}
}

t_bool			take_f64(
		char **input,
		t_f64 *out)
{
	t_f64		number;
	t_size		after;
	char		sign;

	number = 0;
	after = 0;
	sign = **input == '-';
	*input += sign;
	if (!ft_isdigit(**input))
		return (false);
	take_numberf(input, &number);
	*input += **input == '.';
	while (ft_isdigit(**input))
	{
		number = number * 10. + (**input - '0') % 10;
		*input += 1;
		after += 1;
	}
	while (after > 0)
	{
		after -= 1;
		number /= 10;
	}
	*out = sign ? -number : number;
	return (true);
}
