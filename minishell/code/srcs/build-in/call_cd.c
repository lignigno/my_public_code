/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 09:54:00 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// __________________________________________________________________SUBFUNCTION

static void	write_error(t_command *command)
{
	if (!command->argv[1] || !ft_strcmp(command->argv[1], "~"))
		minishell_errorka("HOME not set", "cd");
	else
		minishell_errorka("OLDPWD not set", "cd");
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*set_dir(t_all_var *all, t_command *command)
{
	char	*result;

	if (!command->argv[1])
		result = get_value(all, "HOME");
	else if (!ft_strcmp(command->argv[1], "~")
		|| !ft_strcmp(command->argv[1], "-"))
	{
		if (!ft_strcmp(command->argv[1], "~"))
			result = get_value(all, "HOME");
		else
			result = get_value(all, "OLDPWD");
	}
	else
		result = command->argv[1];
	if (!result)
	{
		write_error(command);
		return (result);
	}
	result = ft_strdup(result);
	if (!result)
		errorka(all, NMA_EXECUTE);
	return (result);
}

// ________________________________________________________________MAIN FUNCTION

int	call_cd(t_all_var *all, t_command *command)
{
	char	*dir;
	char	*tmp;

	dir = set_dir(all, command);
	if (!dir)
		return (1);
	tmp = getcwd(NULL, 0);
	if (!chdir(dir))
	{
		if (command->argv[1] && !ft_strcmp(command->argv[1], "-"))
			write(1, dir, ft_strlen(dir)) && write(1, "\n", 1);
		change_pwd(all);
		change_oldpwd(all, tmp);
		free(dir);
		return (0);
	}
	free(tmp);
	tmp = dir;
	dir = ft_strjoin("cd: ", dir);
	if (!dir)
		errorka(all, NMA_EXECUTE);
	free(tmp);
	minishell_errorka("No such file or directory", dir);
	free(dir);
	return (1);
}
