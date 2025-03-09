/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_headers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:57:30 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 06:56:37 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_HEADERS_H
# define ALL_HEADERS_H

# include <sys/stat.h>
# include <termios.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <curses.h>
# include <stdio.h>
# include <fcntl.h>
# include <term.h>
# include "structs.h"
# include "get_command_line.h"
# include "built_in.h"
# include "errorka.h"
# include "execute.h"
# include "parser.h"
# include "utils.h"
# include "init.h"

# define ON 1
# define OFF 0
# define CUU "\e[A"
# define CUD "\e[B"
# define CUB "\e[D"
# define CUF "\e[C"
# define MINISHELL "\e[1;38;2;0;150;255mmini\e[38;2;65;199;24mshell\e[m"

t_processes	*g_processes;

#endif
