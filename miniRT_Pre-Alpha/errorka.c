/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:07:47 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/09 08:53:23 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void		errorka(t_vars *vars, char *error)
{
	int		length;

	length = ft_strlen(error);
	write(2, "\033[31mError\n\n", 12);
	write(2, error, length);
	cleaner(vars);
	exit(0);
}
