/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 19:55:55 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/12 20:38:40 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*res;

	if (lst == NULL)
		return (NULL);
	out = NULL;
	while (lst != NULL)
	{
		res = ft_lstnew(f(lst->content));
		if (res == NULL)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, res);
		lst = lst->next;
	}
	return (out);
}
