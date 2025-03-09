/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:09:43 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:09:47 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static int	arguments_ended(char *str, size_t *i, int *mark, int *space)
{
	if (*mark == str[*i])
		*mark = 0;
	else if (!*mark && (str[*i] == '\'' || str[*i] == '\"'))
		*mark = str[*i];
	else if (*mark != '\'' && str[*i] == '\\' && str[*i + 1])
		(*i)++;
	else if (!*mark && str[*i] == ' ')
		*space = 1;
	else if (!*mark && (str[*i] == '<' || str[*i] == '>'
			|| (str[*i] == '>' && str[*i + 1] == '>')))
	{
		*i = skip_redirects(str, *i, *mark, 0);
		*space = 1;
		if (str[*i] == ';' || str[*i] == '|')
			return (1);
	}
	else if (!*mark && compare_char_with("|;", str[*i]))
		return (1);
	return (0);
}

size_t	count_args(char *str, size_t i)
{
	size_t	result;
	int		space;
	int		mark;

	result = 0;
	space = 1;
	mark = 0;
	while (str[i])
	{
		if (arguments_ended(str, &i, &mark, &space))
			return (result);
		result += space
			&& (str[i] != ' ' || (str[i] == ' ' && i && str[i - 1] == '\\'))
			&& str[i];
		if (space && str[i] != ' ')
			space = 0;
		i += !!str[i];
	}
	return (result);
}
