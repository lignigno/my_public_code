/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:35 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 07:06:23 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORKA_H
# define ERRORKA_H

# include "all_headers.h"

# define DUMMY_ERROR "string with error\n"
# define NMA_ALL "can\'t memory allocate for all\n"
# define NMA_HISTORI "can\'t memory allocate for history\n"
# define NMA_ENV "can\'t memory allocate for environment\n"
# define CANT_CREATE_HISTOY "can\'t create history\n"
# define CRASH_COMMAND_LINE "crash command line\n"
# define NMA_REPLACE_DOLLAR "can\'t memory allocate for replace dollar\n"
# define CANT_PARSE "my parser crashed, sorry...\n"
# define NMA_EXECUTE "can\'t memory allocate for execute command\n"
# define EXECVE_BAH "problem when calling the command\n"
# define NMA_CONVERT "can\'t memory allocate for execute in call_other\n"
# define NMA_DESTROY_SET "can\'t memory allocate for destroy_commands_set\n"
# define NMA_NOT_VALID_IDENT "can\'t memory allocate for not_valid_identifier\n"
# define CANT_FORK "fork() crashed\n"

void	errorka(t_all_var *all, char *error_str);
void	minishell_errorka(char *error, char *what);

#endif