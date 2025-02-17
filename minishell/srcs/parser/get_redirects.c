/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:10:32 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/01 10:14:18 by rquenten         ###   ########.fr       */
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

static char	*set_need_exit(t_redir	*redirect, char *file_name)
{
	free(file_name);
	redirect->file_name = NULL;
	return (NULL);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*add_output(t_redir *list, char *file_name, char type)
{
	t_redir	*iterator;
	t_redir	*new_redirect;

	if (!file_name)
		return (NULL);
	iterator = list;
	while (iterator->next)
		iterator = iterator->next;
	if (iterator->file_name[0] == -1)
	{
		free(iterator->file_name);
		iterator->file_name = file_name;
		iterator->type = type;
		return (file_name);
	}
	new_redirect = malloc(sizeof(t_redir));
	if (!new_redirect)
		return (set_need_exit(iterator, file_name));
	new_redirect->file_name = file_name;
	new_redirect->type = type;
	new_redirect->next = NULL;
	iterator->next = new_redirect;
	return (file_name);
}

// ________________________________________________________________MAIN FUNCTION

void	get_redirects(t_command *command, char *str, size_t i)
{
	char	*result;
	int		slash;
	int		mark;

	slash = 0;
	mark = 0;
	while (str[i])
	{
		set_flags(str[i], &mark, &slash);
		if (!mark && !slash && compare_char_with("<>", str[i]))
		{
			result = cut_redirection(str, i);
			if (str[i + 1] == '>')
				result = add_output(command->redirect, result, 'a');
			else
				result = add_output(command->redirect, result, str[i]);
			if (!result)
				return ;
		}
		if (!mark && !slash && compare_char_with("|;", str[i]))
			return ;
		i += (str[i] == '>' && str[i + 1] == '>') + 1;
	}
}
