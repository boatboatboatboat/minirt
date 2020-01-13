/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:18:15 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/30 19:08:38 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <minirt.h>

void	assert(
		t_bool condition,
		const char *message,
		t_bool include_errno)
{
	if (condition == false)
		panic(message, include_errno);
}

void	panic(
		const char *message,
		t_bool include_errno)
{
	ft_putstr_fd("Error\n", 2);
	if (include_errno)
		perror(message);
	else
	{
		ft_putstr_fd((char *)message, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(1);
}
