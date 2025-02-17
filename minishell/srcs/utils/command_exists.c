/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:59:13 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 08:00:07 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static void	*free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path[i]);
	free(path);
	return (NULL);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*found_with_path(t_all_var *all, char *command, struct stat *info)
{
	char		*result;
	char		**path;
	int			i;

	result = get_value(all, "PATH");
	if (!result)
		return (NULL);
	path = ft_split(result, ':');
	if (!path)
		errorka(all, NMA_EXECUTE);
	i = -1;
	while (path[++i])
	{
		path[i] = add_char(path[i], '/', -1);
		result = ft_strjoin(path[i], command);
		if (!result)
			errorka(all, NMA_EXECUTE);
		if (!stat(result, info))
			break ;
		free(result);
	}
	if (!path[i])
		return (free_path(path));
	free_path(path);
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	write_minierrorka(char *command, char *str, int need_write)
{
	free(str);
	if (!command[0] && need_write)
		minishell_errorka("command not found", command);
	else if (need_write)
		minishell_errorka("Is a directory", command);
	return (need_write);
}

// ________________________________________________________________MAIN FUNCTION

int	command_exists(t_all_var *all, char *command, char **full_name)
{
	struct stat	info;
	char		*result;

	if (!stat(command, &info))
		result = ft_strdup(command);
	else if (!name_with_path(command))
	{
		result = found_with_path(all, command, &info);
		if (!result)
			return (0);
	}
	else
		return (0);
	if (info.st_mode & S_IFDIR)
	{
		if (!full_name)
			return (write_minierrorka(command, result, 0));
		else
			exit(write_minierrorka(command, result, 1));
	}
	if (!full_name)
		free(result);
	else
		*full_name = result;
	return (1);
}
