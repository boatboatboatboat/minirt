/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:37:12 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/07 18:02:37 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, t_size length)
{
	(void)ft_memset(string, 0, length);
}
