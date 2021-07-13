/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:32:45 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 00:25:20 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// _________________________________________________________________SUBFUNCTIONS

static int	invalid_value(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num < INT_MIN || INT_MAX < num || !num);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static int	number_of_philosophers(char *argv[])
{
	if (!only_nbr(argv[1]))
		return (errorka_1("only digits are accepted", "argv[1]", argv[1]));
	if (ft_strlen(argv[1]) > 3)
		return (errorka_1("I refuse to do it", "argv[1]", argv[1]));
	if (sini(argv[1]) < 2)
		return (errorka_1("I'll just keep quiet", "argv[1]", argv[1]));
	return (1);
}

// ____________________________________________________________________MAIN FUNC

int	checking_input_values(int argc, char *argv[])
{
	char	*arr[4];
	int		i;

	if (argc < 5)
		return (errorka_0("not enough arguments", 0));
	if (argc > 6)
		return (errorka_0("too many arguments", 0));
	if (!number_of_philosophers(argv))
		return (0);
	arr[0] = "argv[2]";
	arr[1] = "argv[3]";
	arr[2] = "argv[4]";
	arr[3] = "argv[5]";
	i = 2;
	while (i < argc)
	{
		if (!only_nbr(argv[i]))
			return (errorka_1("only digits are accepted", arr[i - 2], argv[i]));
		if (ft_strlen(argv[i]) > 10)
			return (errorka_1("the number is too large", arr[i - 2], argv[i]));
		if (invalid_value(argv[i]))
			return (errorka_1("invalid value", arr[i - 2], argv[i]));
		i++;
	}
	return (1);
}
