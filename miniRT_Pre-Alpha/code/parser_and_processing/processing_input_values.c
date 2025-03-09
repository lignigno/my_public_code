/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_input_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:46:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/03/13 13:33:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static int		not_rt_extension(char *rt_file_name)
{
	int		len;

	len = ft_strlen(rt_file_name);
	if (rt_file_name[len - 3] == '.' &&
		rt_file_name[len - 2] == 'r' &&
		rt_file_name[len - 1] == 't')
		return (0);
	return (1);
}

static int		param_save_unnormal(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == '-' &&
		str[1] == '-' &&
		str[2] == 's' &&
		str[3] == 'a' &&
		str[4] == 'v' &&
		str[5] == 'e' &&
		str[6] == '\0')
		return (0);
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			processing_input_values(t_vars *vars, int count, char **value)
{
	if (count == 1 || count > 3)
		errorka(vars, MANY_ARG);
	if (ft_strlen(value[1]) < 3)
		errorka(vars, BAD_FILE_NAME);
	if (not_rt_extension(value[1]))
		errorka(vars, BAD_EXTENSION);
	if (count == 2)
		return ;
	if (param_save_unnormal(value[2]))
		errorka(vars, BAD_SECOND_ARG);
	vars->save = 1;
}
