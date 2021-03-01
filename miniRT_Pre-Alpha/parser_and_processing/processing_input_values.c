/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_input_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:46:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/12 20:34:26 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static int	not_rt_extension(char *rt_file_name)
{
	int		len;

	len = ft_strlen(rt_file_name);
	if (len < 3)
		return (1);
	if (rt_file_name[len - 3] == '.' &&
		rt_file_name[len - 2] == 'r' &&
		rt_file_name[len - 1] == 't')
		return (0);
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void		processing_input_values(t_vars *vars, int count, char **value)
{
	if (count == 1)
		errorka(vars, NO_ARG);
	if (count > 3)
		errorka(vars, MANY_ARG);
	if (ft_strlen(value[1]) < 3)
		errorka(vars, BAD_FILE_NAME);
	if (not_rt_extension(value[1]))
		errorka(vars, BAD_EXTENSION);
	if (count == 3 && ft_strncmp(value[2], "--save", 6))
		errorka(vars, BAD_SECOND_ARG);
	vars->save = count == 3 ? 1 : 0;
}
