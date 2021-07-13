/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:11:51 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 00:56:08 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

// ____________________________________________________________________MAIN FUNC

int	sini(char *str_with_number)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (str_with_number[i])
	{
		num = num * 10 + str_with_number[i] - '0';
		i++;
	}
	return (num);
}
