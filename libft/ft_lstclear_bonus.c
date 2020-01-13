/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 19:36:35 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/09 19:03:58 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*old;

	if (lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		del(curr->content);
		old = curr;
		curr = curr->next;
		free(old);
	}
	*lst = NULL;
}
