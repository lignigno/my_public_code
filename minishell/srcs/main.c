/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:01 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 05:27:50 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

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
		if (!mark && !slash && (compare_char_with(";", str[i]) || !str[i]))
			break ;
		if (slash == 2)
			slash = 0;
		i++;
	}
	return (i);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*destroy_commands_set(t_all_var *all, char *command_line)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = skip_to_separator(command_line, 0);
	len = i;
	while (command_line[len])
		len++;
	result = ft_substr(command_line, i + 1, len - i);
	if (!result)
		errorka(all, NMA_DESTROY_SET);
	free(command_line);
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	free_commands_list(t_command *commands)
{
	t_command	*tmp_command;
	t_redir		*tmp_out;
	int			i;

	while (commands)
	{
		i = -1;
		while (commands->argv[++i])
			free(commands->argv[i]);
		free(commands->argv[i]);
		free(commands->argv);
		while (commands->redirect)
		{
			free(commands->redirect->file_name);
			tmp_out = commands->redirect;
			commands->redirect = commands->redirect->next;
			free(tmp_out);
		}
		tmp_command = commands;
		commands = commands->next;
		free(tmp_command);
	}
}

// ________________________________________________________________MAIN FUNCTION

int	main(int count, char **value, char **env)
{
	t_all_var	*all;
	t_command	*commands_list;
	char		*command_line;

	(void)count;
	(void)value;
	all = init(env);
	while (1)
	{
		write(1, MINISHELL, ft_strlen(MINISHELL));
		write(1, " $ ", 3);
		command_line = get_command_line(all);
		while (command_line[0])
		{
			commands_list = parsing_entered_command(all, command_line);
			if (!commands_list)
				break ;
			execute_command(all, commands_list);
			command_line = destroy_commands_set(all, command_line);
			free_commands_list(commands_list);
		}
		free(command_line);
	}
	return (0);
}
