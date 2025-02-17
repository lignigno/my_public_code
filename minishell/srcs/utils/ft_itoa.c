/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:59:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:59:41 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static int	length_number(long long n)
{
	int	length;

	length = 1;
	if (n > 0)
	{
		while (n > 9)
		{
			n /= 10;
			length++;
		}
	}
	else
	{
		while (n < -9)
		{
			n /= 10;
			length++;
		}
	}
	return (length);
}

char	*ft_itoa(long long n)
{
	int		flag_neg;
	int		length;
	int		length2;
	char	*result;

	flag_neg = 0;
	length = length_number(n);
	length2 = length;
	if (n < 0)
		flag_neg = 1;
	result = (char *)malloc(length + flag_neg + 1);
	if (result == NULL)
		return (NULL);
	while (length)
	{
		if (flag_neg)
			result[--length + flag_neg] = -(n % 10) + 48;
		else
			result[--length + flag_neg] = (n % 10) + 48;
		n /= 10;
	}
	if (flag_neg)
		result[length] = '-';
	result[length2 + flag_neg] = '\0';
	return (result);
}
