/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:52:45 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 23:51:59 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static void	get_it_all_back(t_all_var *all, int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	free_pipes(pipes);
	free_processes();
	unset_keypress(all->term_settings);
	dup2(all->save_stdinput, 0);
	dup2(all->save_stdout, 1);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	command_without_fork(char *command_name)
{
	if (command_name
		&& (!ft_strcmp(command_name, "cd")
			|| !ft_strcmp(command_name, "exit")
			|| !ft_strcmp(command_name, "unset")
			|| !ft_strcmp(command_name, "export")))
		return (1);
	return (0);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	with_fork(t_all_var *all, t_command *command, int **pipes, int i)
{
	int	pid;
	int	exit_code;

	pid = fork();
	if (pid > 0)
		add_process(all, command, pid);
	else if (pid == 0)
	{
		g_processes = NULL;
		exit_code = redirects(command, pipes, i);
		if (!exit_code)
			call_command(all, command);
		exit(exit_code);
	}
	else
		errorka(all, CANT_FORK);
	return (-1);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	without_fork(t_all_var *all, t_command *command, int **pipes, int i)
{
	int	exit_code;

	exit_code = redirects(command, pipes, i);
	if (!exit_code && !ft_strcmp(command->argv[0], "cd"))
		exit_code = call_cd(all, command);
	else if (!exit_code && !ft_strcmp(command->argv[0], "exit"))
		call_exit(all);
	else if (!exit_code && !ft_strcmp(command->argv[0], "unset"))
		exit_code = call_unset(all, command);
	else if (!exit_code)
		exit_code = call_export(all, command);
	return (exit_code);
}

// ________________________________________________________________MAIN FUNCTION

void	execute_command(t_all_var *all, t_command *commands_list)
{
	int	last_exit_code;
	int	**pipes;
	int	status;
	int	count;
	int	i;

	count = creat_pipes(all, commands_list, &pipes);
	last_exit_code = -1;
	i = -1;
	while (++i <= count)
	{
		if (command_without_fork(commands_list->argv[0]))
			last_exit_code = without_fork(all, commands_list, pipes, i);
		else
			last_exit_code = with_fork(all, commands_list, pipes, i);
		commands_list = commands_list->next;
	}
	status = o_my_wait();
	if (last_exit_code < 0)
		all->last_exit_code = WEXITSTATUS(status);
	else
		all->last_exit_code = last_exit_code;
	get_it_all_back(all, pipes);
}
