/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:10:27 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:10:28 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static void	set_flags(char ch, int *mark, int *slash)
{
	if (!*slash && ch == *mark)
		*mark = 0;
	else if (!*mark && !*slash && (ch == '\'' || ch == '\"'))
		*mark = ch;
	else if (*slash)
		*slash = 2;
	else if (*mark != '\'' && !*slash && ch == '\\')
		*slash = 1;
	else if (!*mark && !*slash && compare_char_with(" |;<>", ch))
		*slash = 3;
}

static int	need_add_char(char ch, int mark, int slash)
{
	if (slash == 3
		|| slash == 1
		|| (slash != 2 && ((mark && mark == ch)
				|| !mark) && (ch == '\'' || ch == '\"')))
		return (0);
	return (1);
}

static void	*init_this(char **result, int *mark, int *slash)
{
	*result = malloc(sizeof(char));
	if (!*result)
		return (*result);
	*mark = 0;
	*slash = 0;
	**result = '\0';
	return ((void *)1);
}

static void	if_caught_redirection(char *str, size_t *i, int mark, int slash)
{
	if (!mark && !slash && (str[*i] == '<' || str[*i] == '>'
			|| (str[*i] == '>' && str[*i + 1] == '>')))
	{
		*i = skip_redirects(str, *i, mark, slash);
		*i = skip_spaces(str, *i);
	}
}

char	*get_one_arg(char *str, size_t *i)
{
	int		mark;
	int		slash;
	char	*result;

	if (!init_this(&result, &mark, &slash))
		return (NULL);
	if_caught_redirection(str, i, mark, slash);
	while (str[*i])
	{
		set_flags(str[*i], &mark, &slash);
		if (need_add_char(str[*i], mark, slash))
		{
			result = add_char(result, str[*i], -1);
			if (!result)
				return (result);
			slash = 0;
		}
		if (slash == 3)
			break ;
		(*i)++;
	}
	return (result);
}
