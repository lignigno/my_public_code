/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:10:44 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/02 00:27:46 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// ________________________________________________________________MAIN FUNCTION

t_command	*parsing_entered_command(t_all_var *all, char *command_line)
{
	t_command	*commands_list;

	if (!validate_sintax(command_line))
	{
		minishell_errorka("syntax error", NULL);
		return (NULL);
	}
	command_line = replace_dollar_variable(all, command_line);
	commands_list = processing_of_command_line(command_line);
	if (!commands_list)
		errorka(all, CANT_PARSE);
	free(command_line);
	return (commands_list);
}
