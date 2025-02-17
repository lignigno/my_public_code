/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:56:00 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 08:56:33 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum e_flags
{
	MARK,
	SLASH,
	DOLLAR,
	SEPARATOR,
	COUNT_FLAGS,
};

typedef struct s_processes
{
	int		pid;
	char	*name;
	void	*next;
}				t_processes;

typedef struct s_redir
{
	char	*file_name;
	char	type;
	void	*next;
}				t_redir;

typedef struct s_history
{
	char		*command_line;
	size_t		cursor;
	void		*next;
	void		*back;
}				t_history;

typedef struct s_env
{
	char		*variable;
	char		*value;
	void		*next;
}				t_env;

typedef struct s_command
{
	t_redir		*redirect;
	char		**argv;
	int			pipe;
	void		*next;
}				t_command;

typedef struct s_all_var
{
	struct termios	term_settings;
	int				save_stdout;
	int				save_stdinput;
	int				debug;
	int				inout;
	char			key[3];
	int				last_exit_code;
	char			**error_log_list;
	t_env			*env;
	t_env			*exp;
	t_history		*history;
}				t_all_var;

#endif