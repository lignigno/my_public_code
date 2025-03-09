/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:52:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 08:05:42 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// __________________________________________________________________SUBFUNCTION

static void	chek_builtin(t_all_var *all, t_command *command)
{
	if (!ft_strcmp(command->argv[0], "echo"))
		call_echo(command);
	else if (!ft_strcmp(command->argv[0], "env"))
		call_env(all);
	else if (!ft_strcmp(command->argv[0], "pwd"))
		call_pwd();
}

// ________________________________________________________________MAIN FUNCTION

void	call_command(t_all_var *all, t_command *command)
{
	char	*full_name;

	if (!command->argv[0])
		exit(0);
	chek_builtin(all, command);
	if (command_exists(all, command->argv[0], &full_name))
		call_other(all, command, full_name);
	else
	{
		if (!get_value(all, "PATH") || name_with_path(command->argv[0]))
			minishell_errorka("No such file or directory", command->argv[0]);
		else
			minishell_errorka("command not found", command->argv[0]);
		exit(127);
	}
}
