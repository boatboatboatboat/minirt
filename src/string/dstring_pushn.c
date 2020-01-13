/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring_pushn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:52:28 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:44:35 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dstring.h>
#include <libft.h>
#include <stdlib.h>

t_bool		dstring_pushn(
		t_dstring *self,
		const char *str,
		t_size length)
{
	char			*new;

	while ((self->size + length) >= self->capacity)
		self->capacity *= 2;
	new = malloc(self->capacity * sizeof(char));
	if (new == NULL)
	{
		free(self->raw);
		return (false);
	}
	ft_memcpy(new, self->raw, self->size);
	ft_memcpy(new + self->size, str, length);
	free(self->raw);
	self->size += length;
	self->raw = new;
	return (true);
}
