/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:43:26 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 19:43:28 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	negativ_write(int n, int fd)
{
	char	outch;
	long	long_n;

	if (n > -10)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		write(fd, "-", 1);
		long_n = n;
		long_n *= -1;
		outch = long_n % 10 + 48;
		long_n /= 10;
		ft_putnbr_fd((int)long_n, fd);
		write(fd, &outch, 1);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	char	outch;

	if (n < 0)
		negativ_write(n, fd);
	else if (n < 10)
	{
		outch = n + 48;
		write(fd, &outch, 1);
	}
	else
	{
		outch = n % 10 + 48;
		n /= 10;
		ft_putnbr_fd(n, fd);
		write(fd, &outch, 1);
	}
}
