/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:28:25 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/12 03:43:42 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	sign = 0;
	result = 0;
	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		++i;
	sign = str[i] == '-' ? -1 : 1;
	i = str[i] == '-' || str[i] == '+' ? i + 1 : i;
	while ('0' <= str[i] && str[i] <= '9')
		result = result * 10 + sign * (str[i++] - 48);
	return (result);
}
