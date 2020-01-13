/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:49:46 by dpattij           #+#    #+#             */
/*   Updated: 2019/12/21 15:49:46 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dstring.h>

t_bool		dstring_new(t_dstring *output)
{
	output->capacity = 4;
	output->size = 0;
	output->raw = malloc(output->capacity * sizeof(char));
	return (output->raw != NULL);
}
