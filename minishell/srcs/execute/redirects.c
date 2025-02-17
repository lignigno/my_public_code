/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:53:16 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/03 01:10:36 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// __________________________________________________________________SUBFUNCTION

static int	open_file(t_redir *redirect)
{
	t_redir	*iterator;
	int		file;

	iterator = redirect;
	file = -1;
	while (iterator)
	{
		if (iterator->type == '<')
			file = open(iterator->file_name, O_RDONLY);
		else if (iterator->type == '>')
			file = open(iterator->file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
			file = open(iterator->file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (file < 0)
		{
			minishell_errorka("No such file or directory", iterator->file_name);
			return (1);
		}
		if (iterator->type == '<')
			dup2(file, 0);
		else
			dup2(file, 1);
		iterator = iterator->next;
	}
	return (0);
}

// ________________________________________________________________MAIN FUNCTION

int	redirects(t_command *command, int **pipes, int i)
{
	t_redir	*iterator;
	int		error;
	int		flags;

	error = 0;
	flags = 3;
	iterator = command->redirect;
	while (iterator && iterator->file_name[0] != -1 && !error)
	{
		error = open_file(iterator);
		if (!error && iterator->type == '<')
			flags &= 2;
		else if (!error)
			flags &= 1;
		iterator = iterator->next;
	}
	if (!error && (i > 0) && (flags & 1))
		dup2(pipes[i - 1][0], 0);
	if (!error && (command->pipe) && (flags & 2))
		dup2(pipes[i][1], 1);
	return (error);
}
