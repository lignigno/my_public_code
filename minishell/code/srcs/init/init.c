/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:57:10 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 08:56:14 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static int	check_minishell(void)
{
	size_t	len;

	if (g_processes->name)
	{
		len = ft_strlen(g_processes->name);
		if (len > 8
			&& g_processes->name[len - 9] == 'm'
			&& g_processes->name[len - 8] == 'i'
			&& g_processes->name[len - 7] == 'n'
			&& g_processes->name[len - 6] == 'i'
			&& g_processes->name[len - 5] == 's'
			&& g_processes->name[len - 4] == 'h'
			&& g_processes->name[len - 3] == 'e'
			&& g_processes->name[len - 2] == 'l'
			&& g_processes->name[len - 1] == 'l')
			return (1);
		return (0);
	}
	return (0);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	process_exist(void)
{
	t_processes	*iterator;
	int			count;

	count = 0;
	iterator = g_processes;
	while (iterator)
	{
		count++;
		iterator = iterator->next;
	}
	if (!count)
		return (0);
	if (count == 1)
		return (!check_minishell());
	return (1);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	processing_signal(int signal)
{
	if (signal == SIGQUIT && process_exist())
	{
		destroy_processes(signal, -1);
		write(2, "Quit: 3\n", 8);
	}
	else if (signal == SIGINT && process_exist())
	{
		destroy_processes(signal, -1);
		write(2, "\n", 1);
	}
}

// ________________________________________________________________MAIN FUNCTION

t_all_var	*init(char **env)
{
	t_all_var	*all;

	all = malloc(sizeof(t_all_var));
	if (all == NULL)
		errorka(all, NMA_ALL);
	all->env = init_env(all, env, OFF);
	all->exp = init_env(all, env, ON);
	change_pwd(all);
	change_oldpwd(all, NULL);
	tcgetattr(0, &all->term_settings);
	g_processes = NULL;
	signal(SIGQUIT, processing_signal);
	signal(SIGINT, processing_signal);
	ft_bzero(all->key, 3);
	all->last_exit_code = 0;
	all->save_stdinput = dup(0);
	all->save_stdout = dup(1);
	return (all);
}
