/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:52:33 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:52:34 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static int	count_pipes(t_command *commands_list)
{
	int	result;

	result = 0;
	while (commands_list && commands_list->pipe)
	{
		result++;
		commands_list = commands_list->next;
	}
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	**init_result(t_all_var *all, int count)
{
	int	**result;
	int	i;

	result = malloc(count * sizeof(int *) + 1);
	if (!result)
		errorka(all, NMA_EXECUTE);
	i = 0;
	while (i <= count)
		result[i++] = NULL;
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	init_fd_arrays(t_all_var *all, int	**pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
		{
			free_pipes(pipes);
			errorka(all, NMA_EXECUTE);
		}
		i++;
	}
}

// ________________________________________________________________MAIN FUNCTION

int	creat_pipes(t_all_var *all, t_command *commands_list, int ***pipes)
{
	int	i;
	int	count;
	int	**result;

	count = count_pipes(commands_list);
	result = init_result(all, count);
	init_fd_arrays(all, result, count);
	i = 0;
	while (i < count)
	{
		pipe(result[i]);
		i++;
	}
	*pipes = result;
	return (count);
}
