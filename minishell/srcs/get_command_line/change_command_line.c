/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:53:33 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:53:34 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

void	put_signal(t_all_var *all, t_history *current_command, char ch)
{
	size_t	len;

	len = ft_strlen(current_command->command_line);
	if (ch == '\3')
	{
		current_command->command_line[0] = '\0';
		current_command->cursor = 0;
		write(1, "\n", 1);
		write(1, MINISHELL, ft_strlen(MINISHELL));
		write(1, " $ ", 3);
		save_cursor_position();
	}
	if (ch == '\4' && len == 0)
		call_exit(all);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

char	*add_char_in_command(t_all_var *all, char *command, char ch)
{
	char	*result;
	size_t	len;

	len = ft_strlen(command);
	result = malloc(len * sizeof(char) + 2);
	if (result == NULL)
		errorka(all, CRASH_COMMAND_LINE);
	result[len + 1] = '\0';
	result[len] = ch;
	while (len > 0)
	{
		len--;
		result[len] = command[len];
	}
	free(command);
	write(1, &ch, 1);
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	trim_key(char key[], int i)
{
	int		index;

	index = -1;
	while (++index < 3)
	{
		if (index + i + 1 < 3)
			key[index] = key[index + i + 1];
		else
			key[index] = '\0';
	}
}

// ________________________________________________________________MAIN FUNCTION

int	change_command_line(t_all_var *all, t_history *command)
{
	char	*line;
	int		i;

	line = command->command_line;
	i = -1;
	while (all->key[++i] != '\0' && i < 3)
	{
		if (all->key[i] == '\t')
			continue ;
		else if (all->key[i] == 3 || all->key[i] == 4 || all->key[i] == 28)
			put_signal(all, command, all->key[i]);
		else if (all->key[i] == '\177' && ft_strlen(line))
			backspace(line);
		else if (all->key[i] == '\n')
		{
			trim_key(all->key, i);
			command->command_line = line;
			write(1, "\n", 1);
			return (0);
		}
		else if (31 < all->key[i] && all->key[i] < 127)
			line = add_char_in_command(all, line, all->key[i]);
	}
	command->command_line = line;
	return (1);
}
