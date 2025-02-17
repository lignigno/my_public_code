/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:11:02 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/02 00:23:03 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static int	init_this(char **result, int flags[])
{
	*result = malloc(sizeof(char));
	if (!*result)
		return (0);
	**result = '\0';
	flags[MARK] = 0;
	flags[SLASH] = 0;
	flags[DOLLAR] = 0;
	return (1);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	set_flags(char ch, int f[])
{
	f[DOLLAR] = 0;
	if (f[SLASH] == 2)
		f[SLASH] = 0;
	if (!f[SLASH] && ch == f[MARK])
		f[MARK] = 0;
	else if (!(f[MARK]) && !f[SLASH] && compare_char_with("\'\"", ch))
		f[MARK] = ch;
	else if (f[MARK] != '\'' && ch == '\\')
		f[SLASH] = 1;
	else if (f[SLASH])
		f[SLASH]++;
	else if ((f[MARK] != '\'' && !f[SLASH] && ch == '$')
		|| (!f[MARK] && !f[SLASH] && ch == '~'))
		f[DOLLAR] = 1;
}

// ________________________________________________________________MAIN FUNCTION

char	*replace_dollar_variable(t_all_var *all, char *line)
{
	int		flags[COUNT_FLAGS];
	char	*result;
	size_t	i;

	if (!init_this(&result, flags))
		errorka(all, NMA_REPLACE_DOLLAR);
	i = 0;
	while (line[i])
	{
		set_flags(line[i], flags);
		if (flags[DOLLAR])
			result = replace(all, line, &i, result);
		else
		{
			result = add_char(result, line[i], -1);
			if (!result)
				errorka(all, NMA_REPLACE_DOLLAR);
		}
		i += !!line[i];
	}
	return (result);
}
