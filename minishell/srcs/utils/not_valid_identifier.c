/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_valid_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:01:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:01:31 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// __________________________________________________________________SUBFUNCTION

static int	check_arg(char *arg)
{
	size_t	i;

	i = 0;
	while (valid_char(arg[i], i))
		i++;
	if (!arg[i] || (compare_char_with("+=", arg[i]) && i > 0))
		return (0);
	return (1);
}

// ________________________________________________________________MAIN FUNCTION

int	not_valid_identifier(t_all_var *all, char *func, char *arg, int *exit_code)
{
	char	*tmp;

	*exit_code = check_arg(arg);
	if (*exit_code)
	{
		tmp = ft_strjoin(func, ": `");
		if (!tmp)
			errorka(all, NMA_NOT_VALID_IDENT);
		free(tmp);
		tmp = ft_strjoin(tmp, arg);
		tmp = add_char(tmp, '\'', -1);
		if (!tmp)
			errorka(all, NMA_NOT_VALID_IDENT);
		minishell_errorka("not a valid identifier", tmp);
		free(tmp);
	}
	return (*exit_code);
}
