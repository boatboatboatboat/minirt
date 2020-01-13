/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:09:13 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:51:57 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int chr)
{
	return ((chr >= 0x09 && chr <= 0x0d) || chr == ' ');
}