/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:34:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 00:56:14 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// ____________________________________________________________________MAIN FUNC

void	ft_putnbr(size_t n, int fd)
{
	char	str[20];
	int		len;
	int		i;
	char	buff;

	len = 0;
	while (n || len == 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len++;
	}
	str[len] = '\0';
	i = 0;
	while (i < len / 2)
	{
		buff = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = buff;
		i++;
	}
	write(fd, str, len);
}
