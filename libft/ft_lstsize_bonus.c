/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 19:23:53 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/04 21:16:14 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		length;

	length = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		length += 1;
	}
	return (length);
}
