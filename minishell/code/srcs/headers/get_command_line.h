/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:52 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:54:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_COMMAND_LINE_H
# define GET_COMMAND_LINE_H

# include "all_headers.h"

# define TEXT 0
# define SIGNAL 1
# define COMAND 2
# define EXIT 3
# define UP "\e[A"
# define DW "\e[B"
# define RG "\e[C"
# define LF "\e[D"

void	set_keypress(struct termios stored_settings);
void	unset_keypress(struct termios stored_settings);
char	*get_command_line(t_all_var *all);
int		change_command_line(t_all_var *all, t_history *command);
void	backspace(char *str);
void	save_cursor_position(void);
void	reset_cursor_position(void);
void	clear_after_cursor(void);

#endif