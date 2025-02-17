/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:11:13 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/02 00:21:14 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static char	*get_varname(t_all_var *all, char *line, size_t *i)
{
	char	*result;
	size_t	j;

	result = malloc(sizeof(char));
	if (!result)
		errorka(all, NMA_REPLACE_DOLLAR);
	j = 0;
	result[0] = '\0';
	while (line[*i] && valid_char(line[*i], j))
	{
		result = add_char(result, line[*i], j);
		if (!result)
			errorka(all, NMA_REPLACE_DOLLAR);
		(*i)++;
		j++;
	}
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*add_value(t_all_var *all, char *result, char *value, int flag)
{
	char	*tmp;

	if (!flag)
		value = get_value(all, value);
	if (value || flag)
	{
		if (flag)
			value = ft_itoa(all->last_exit_code);
		else
			value = ft_strdup(value);
		if (!value)
			errorka(all, NMA_REPLACE_DOLLAR);
		tmp = result;
		result = ft_strjoin(result, value);
		if (!result)
			errorka(all, NMA_REPLACE_DOLLAR);
		free(tmp);
		free(value);
	}
	return (result);
}

// ________________________________________________________________MAIN FUNCTION

char	*replace(t_all_var *all, char *line, size_t *i, char *dst)
{
	char	*result;
	char	*var_name;

	result = dst;
	if (line[*i] == '~')
		return (add_value(all, result, "HOME", 0));
	(*i)++;
	if (line[*i] == '?')
		return (add_value(all, result, NULL, 1));
	else if (!valid_char(line[*i], 1))
	{
		(*i)--;
		result = add_char(result, '$', -1);
		if (!result)
			errorka(all, NMA_REPLACE_DOLLAR);
		return (result);
	}
	if ('0' <= line[*i] && line[*i] <= '9')
		return (result);
	var_name = get_varname(all, line, i);
	result = add_value(all, result, var_name, 0);
	free(var_name);
	(*i)--;
	return (result);
}
