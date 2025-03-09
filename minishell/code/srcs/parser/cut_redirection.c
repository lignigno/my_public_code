/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:09:56 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/01 10:16:42 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static void	set_flags(char ch, int *mark, int *slash)
{
	if (*slash == 2)
		*slash = 0;
	if (!*slash && ch == *mark)
		*mark = 0;
	else if (!*mark && !*slash && compare_char_with("\'\"", ch))
		*mark = ch;
	else if (*slash)
		(*slash)++;
	else if (*mark != '\'' && ch == '\\')
		*slash = 1;
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	need_add_char(char ch, int mark, int slash)
{
	if (slash == 1 || (slash != 2 && ((mark && mark == ch)
				|| !mark) && (ch == '\'' || ch == '\"')))
		return (0);
	return (1);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	init_this(char **result, int *mark, int *slash)
{
	*result = malloc(sizeof(char));
	if (!*result)
		return (0);
	**result = '\0';
	*slash = 0;
	*mark = 0;
	return (1);
}

// ________________________________________________________________MAIN FUNCTION

char	*cut_redirection(char *command_line, size_t i)
{
	char	*result;
	int		slash;
	int		mark;

	if (!init_this(&result, &mark, &slash))
		return (NULL);
	i += 1 + (command_line[i + 1] == '>');
	i = skip_spaces(command_line, i);
	while (command_line[i])
	{
		set_flags(command_line[i], &mark, &slash);
		if (!slash && !mark && compare_char_with(" <>|;", command_line[i]))
			return (result);
		if (need_add_char(command_line[i], mark, slash))
		{
			result = add_char(result, command_line[i], -1);
			if (!result)
				free(result);
			if (!result)
				return (result);
		}
		i++;
	}
	return (result);
}
