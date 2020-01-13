/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:43:55 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 05:53:30 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSTRING_H
# define DSTRING_H

# include <minirt.h>
# include <libft.h>

typedef struct		s_dstring
{
	char			*raw;
	t_size			capacity;
	t_size			size;
}					t_dstring;

t_bool				dstring_new(t_dstring *output);
t_bool				dstring_push_str(
	t_dstring *self,
	const char *str);
t_bool				dstring_pushn(
	t_dstring *self,
	const char *str,
	t_size length);

#endif
