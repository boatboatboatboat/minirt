/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:27 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/05 05:55:23 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <libft.h>
# include <minirt.h>

typedef struct		s_vector
{
	t_size	size;
	t_size	capacity;
	t_size	type_size;
	char	*raw;
}					t_vector;

t_bool				vector_with_capacity(
		t_vector *self,
		t_size type_size,
		t_size capacity);

t_bool				vector_new(
		t_vector *self,
		t_size type_size);

t_bool				vector_resize(
		t_vector *self,
		t_size capacity);

t_bool				vector_get(
		t_vector *self,
		t_size index,
		void *out);

t_bool				vector_set(
		t_vector *self,
		t_size index,
		void *value);

t_bool				vector_push(
		t_vector *self,
		void *value);

t_bool				vector_pop(
		t_vector *self,
		void *out);

t_bool				vector_getr(
		t_vector *self,
		t_size index,
		void **value);

t_bool				vector_set(
		t_vector *self,
		t_size index,
		void *value);

void				vector_destroy(t_vector *self);

#endif
