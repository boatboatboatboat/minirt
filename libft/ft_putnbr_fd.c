/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:47:46 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/01 18:52:38 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_descent(long n, int fd)
{
	if (n > 9)
		putnbr_descent(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	n_cast;

	n_cast = (long)n;
	if (n_cast < 0)
	{
		ft_putchar_fd('-', fd);
		n_cast *= -1;
	}
	if (n_cast > 9)
		putnbr_descent(n_cast / 10, fd);
	ft_putchar_fd((n_cast % 10) + '0', fd);
}
