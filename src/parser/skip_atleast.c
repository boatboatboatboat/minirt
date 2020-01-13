/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_atleast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:53:00 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/21 19:14:27 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

t_bool	skip_atleast(
		char **input,
		char matcher,
		t_size times)
{
	t_size occurs;

	occurs = 0;
	while ((*input)[occurs] == matcher)
		occurs += 1;
	*input += occurs;
	return (occurs >= times);
}
