/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_of_command_line.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:10:55 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:10:55 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static t_redir	*init_redirect(void)
{
	t_redir	*result;

	result = malloc(sizeof(t_redir));
	if (!result)
		return (NULL);
	result->file_name = malloc(2 * sizeof(char));
	if (!result->file_name)
	{
		free(result);
		return (NULL);
	}
	result->file_name[0] = -1;
	result->file_name[1] = '\0';
	result->type = '\0';
	result->next = NULL;
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	add_command(t_command **list)
{
	t_command	*iterator;
	t_command	*new_command;

	new_command = malloc(sizeof(t_command));
	if (!new_command)
		return (0);
	new_command->redirect = init_redirect();
	if (!new_command->redirect)
		return (0);
	new_command->pipe = 0;
	new_command->argv = NULL;
	((t_command *)new_command)->next = NULL;
	if (!(*list))
		return (((*list = new_command) || 1));
	iterator = *list;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new_command;
	return (1);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	bad(t_command *result)
{
	t_redir	*iterator;

	if (!result->argv)
		return (1);
	iterator = result->redirect;
	while (iterator)
	{
		if (!iterator->file_name)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static size_t	skip_to_separator(char *str, size_t i)
{
	int		mark;
	int		slash;

	mark = 0;
	slash = 0;
	while (str[i])
	{
		if (!slash && str[i] == mark)
			mark = 0;
		else if (!mark && !slash && (str[i] == '\'' || str[i] == '\"'))
			mark = str[i];
		else if (slash)
			slash = 2;
		else if (mark != '\'' && !slash && str[i] == '\\')
			slash = 1;
		if (!mark && !slash && (compare_char_with("|;", str[i]) || !str[i]))
			break ;
		if (slash == 2)
			slash = 0;
		i++;
	}
	return (i);
}

// ________________________________________________________________MAIN FUNCTION

t_command	*processing_of_command_line(char *command_line)
{
	size_t		i;
	t_command	*result;
	t_command	*iterator;

	i = 0;
	result = NULL;
	while ((command_line[i] || !result) && command_line[i] != ';')
	{
		if (!add_command(&result))
			return (NULL);
		if (!i)
			iterator = result;
		else
			iterator = iterator->next;
		iterator->argv = get_args(command_line, i);
		get_redirects(iterator, command_line, i);
		if (bad(iterator))
			return (NULL);
		i = skip_to_separator(command_line, i);
		if (command_line[i] == '|')
			iterator->pipe = 1;
		i += !!command_line[i] && command_line[i] != ';';
	}
	return (result);
}
