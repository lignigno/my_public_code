/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:37:11 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/16 14:21:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

static void		get_num(t_vars *vars, char *str, int *i, int mode)
{
	int			*number;

	number = mode == 'w' ? &vars->w_win : &vars->h_win;
	skip_space(str, i);
	if (str[*i] == '0' || str[*i] == '-')
		errorka(vars, INCORRECT_RESOLUTION);
	while ('0' <= str[*i] && str[*i] <= '9')
		*number = *number * 10 + str[(*i)++] - '0';
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_resolution(t_vars *vars, char *str)
{
	int		i;

	i = 1;
	if (str[i] != ' ')
		errorka(vars, INCORRECT_RESOLUTION);
	get_num(vars, str, &i, 'w');
	get_num(vars, str, &i, 'h');
	if (str[i] != '\0' || vars->w_win == 0 || vars->h_win == 0)
		errorka(vars, INCORRECT_RESOLUTION);
}
