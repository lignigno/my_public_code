/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:09:22 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:09:23 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "all_headers.h"

size_t		count_args(char *str, size_t i);
char		*cut_redirection(char *command_line, size_t i);
char		**get_args(char *str, size_t i);
char		*get_one_arg(char *str, size_t *i);
void		get_redirects(t_command *command, char *command_line, size_t i);
t_command	*parsing_entered_command(t_all_var *all, char *command_line);
t_command	*processing_of_command_line(char *command_line);
char		*replace_dollar_variable(t_all_var *all, char *line);
char		*replace(t_all_var *all, char *line, size_t *i, char *dst);
int			validate_sintax(char *str);

#endif