/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:47:50 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 03:59:55 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <libft.h>

# define EPSILON 1e-6
# define LIGHT_MULT 40.0

# ifndef IS_BONUS
#  define IS_BONUS 0
#  define THREAD_COUNT 1
# else
#  ifndef THREAD_COUNT
#   define THREAD_COUNT 16
#  endif
# endif

typedef unsigned char	t_u8;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;
typedef unsigned long	t_u64;
typedef double			t_f64;
typedef char			t_i8;
typedef short			t_i16;
typedef int				t_i32;
typedef long			t_i64;

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

void	panic(
		const char *message,
		t_bool include_errno);
void	assert(
		t_bool condition,
		const char *message,
		t_bool include_errno);
t_f64	rad(t_f64 degrees);
t_f64	deg(t_f64 radians);
t_bool	solve_quad(
		t_f64	abc[3],
		t_f64	x[2]);

#endif
