/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_parser_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:44:04 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/29 13:42:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** FUNCTION NAME_:__________________________________________GET INT NUM IN RANGE
** ________________________________________________________________MAIN FUNCTION
*/

int				get_int_num_in_range(char **str, long *num, int from, int to)
{
	int			first_zero;
	int			count_of_digit;
	int			minus;

	count_of_digit = 0;
	minus = **str == '-' ? -1 : 1;
	(*str) = **str == '-' ? (*str) + 1 : (*str);
	*num = '0' <= **str && **str <= '9' ? 0 : from - 1;
	first_zero = **str == '0' ? 1 : 0;
	while ('0' <= **str && **str <= '9' && ++count_of_digit)
		*num = *num * 10 + minus * (*(*str)++ - '0');
	if ((first_zero && *num != 0) || (count_of_digit > 1 && *num == 0))
		return (0);
	return (from <= *num && *num <= to ? 1 : 0);
}

/*
** FUNCTION NAME_:__________________________________________GET DBL NUM IN RANGE
** __________________________________________________________________SUBFUNCTION
*/

static int		get_fract_part(char **str, long number, double *num, int minus)
{
	int			dot;

	dot = 1;
	while ('0' <= **str && **str <= '9')
	{
		number = number * 10 + minus * (**str - '0');
		(*str)++;
		dot++;
	}
	if (dot == 1)
		return (0);
	*num = number;
	while (--dot)
		*num /= 10;
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
**
** cases when the function returns 0
**
** {!} means the following rule :
** {!012.} any characters not equal to "012."
**
** "{!0123456789}"
** "0.{!0123456789}"
** "21.{!0123456789}"
*/

int				get_dbl_num_in_range(char **str, double *num, int from, int to)
{
	long		number;
	int			minus;

	number = 0;
	if (('9' < **str || **str < '0') && **str != '-')
		return (0);
	minus = **str == '-' ? -1 : 1;
	if (**str == '0')
	{
		if (*++(*str) != '.')
			return (!(*num = 0));
		(*str)++;
		if (!get_fract_part(str, number, num, minus))
			return (0);
		return (from <= *num && *num <= to ? 1 : 0);
	}
	if (!get_int_num_in_range(str, &number, from, to))
		return (0);
	*num = number;
	if (*(*str) != '.')
		return (from <= *num && *num <= to ? 1 : 0);
	(*str)++;
	if (!get_fract_part(str, number, num, minus))
		return (0);
	return (from <= *num && *num <= to ? 1 : 0);
}

/*
**int				main(int argc, char **argv)
**{
**	if (argc == 1)
**	{
**		printf("\033[31;1mТы долбаёб\n");
**		return (0);
**	}
**	t_vars		vars;
**	double		num;
**
**	vars.ambient = 0;
**	printf("the received value : %i\n",
**get_dbl_num_in_range(&argv[1], &num, -3, 4));
**	printf("num : %f\n", num);
**	return 0;
**}
*/
