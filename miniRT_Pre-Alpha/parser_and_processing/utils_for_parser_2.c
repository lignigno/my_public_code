/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_parser_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 06:41:03 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/29 14:19:00 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** FUNCTION NAME_:_______________________________________________GET COORDINATES
** ________________________________________________________________MAIN FUNCTION
*/

int				get_coordinates(char **str, double *coordinates)
{
	if (!get_dbl_num_in_range(str, &coordinates[0], INT_MIN + 1, INT_MAX))
		return (0);
	if (*(*str)++ != ',')
		return (0);
	if (!get_dbl_num_in_range(str, &coordinates[1], INT_MIN + 1, INT_MAX))
		return (0);
	if (*(*str)++ != ',')
		return (0);
	if (!get_dbl_num_in_range(str, &coordinates[2], INT_MIN + 1, INT_MAX))
		return (0);
	return (1);
}

/*
** FUNCTION NAME_:_______________________________________________GET COORDINATES
** __________________________________________________________________SUBFUNCTION
**
** if set comma : need to skip the comma
*/

static int		get_spectrum(char **str, long *spectrum, int comma)
{
	if (!get_int_num_in_range(str, spectrum, 0, 255))
		return (0);
	if (!comma)
		return (1);
	if (*(*str)++ != ',')
		return (0);
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

int				add_rgb(char **str, int *color)
{
	long		spectrum;

	if (!get_spectrum(str, &spectrum, 1))
		return (0);
	*color = (*color << 8) | spectrum;
	if (!get_spectrum(str, &spectrum, 1))
		return (0);
	*color = ((long)*color << 8) | spectrum;
	if (!get_spectrum(str, &spectrum, 0))
		return (0);
	*color = ((long)*color << 8) | spectrum;
	return (1);
}
