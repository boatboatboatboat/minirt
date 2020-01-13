/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring_push_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:52:28 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/02 17:45:51 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dstring.h>
#include <libft.h>
#include <stdlib.h>

t_bool		dstring_push_str(
		t_dstring *self,
		const char *str)
{
	t_size			length;
	char			*new;

	length = ft_strlen(str);
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
