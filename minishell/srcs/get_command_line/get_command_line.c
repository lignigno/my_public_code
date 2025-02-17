/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:53:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:53:46 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static t_history	*add_new_history_without_command(t_all_var *all)
{
	t_history	*new_history;
	char		*command_line;

	if (all->history != NULL && all->history->command_line[0] == '\0')
		return (all->history);
	new_history = malloc(sizeof(t_history));
	if (new_history == NULL)
		errorka(all, NMA_HISTORI);
	command_line = malloc(sizeof(char));
	if (command_line == NULL)
		errorka(all, NMA_HISTORI);
	command_line[0] = '\0';
	new_history->command_line = command_line;
	new_history->cursor = 0;
	new_history->next = all->history;
	new_history->back = NULL;
	if (all->history != NULL)
		all->history->back = new_history;
	all->history = new_history;
	return (new_history);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	get_key(t_all_var *all)
{
	int	readed;

	readed = read(0, all->key, 3);
	if (readed < 0)
		errorka(all, CRASH_COMMAND_LINE);
	return (readed);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	switch_history(t_history **current_history, char key[])
{
	char	*command_line;

	if (!ft_strncmp(key, UP, 3))
	{
		if ((*current_history)->next != NULL)
			*current_history = (*current_history)->next;
	}
	if (!ft_strncmp(key, DW, 3))
	{
		if ((*current_history)->back != NULL)
			*current_history = (*current_history)->back;
	}
	command_line = (*current_history)->command_line;
	reset_cursor_position();
	clear_after_cursor();
	write(1, command_line, ft_strlen(command_line));
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	key_execute(t_all_var *all, t_history **current_command)
{
	if (!ft_strncmp(all->key, UP, 3) || !ft_strncmp(all->key, DW, 3)
		|| !ft_strncmp(all->key, RG, 3) || !ft_strncmp(all->key, LF, 3))
		switch_history(current_command, all->key);
	else
		return (change_command_line(all, *current_command));
	return (1);
}

// ________________________________________________________________MAIN FUNCTION

char	*get_command_line(t_all_var *all)
{
	t_history	*current_command;
	int			readed;

	current_command = add_new_history_without_command(all);
	set_keypress(all->term_settings);
	tgetent(0, "xterm-256color");
	save_cursor_position();
	tputs(tgetstr("st", NULL), 1, ft_putchar);
	while (1)
	{
		if (all->key[0] == '\0')
			readed = get_key(all);
		readed = key_execute(all, &current_command);
		if (readed == 0)
			break ;
		ft_bzero(all->key, 3);
	}
	unset_keypress(all->term_settings);
	return (ft_strdup(current_command->command_line));
}
