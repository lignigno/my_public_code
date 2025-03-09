/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:41 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:54:42 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "all_headers.h"

void	call_command(t_all_var *all, t_command *command);
void	call_other(t_all_var *all, t_command *command, char *full_name);
int		creat_pipes(t_all_var *all, t_command *commands_list, int ***pipes);
void	execute_command(t_all_var *all, t_command *commands);
int		redirects(t_command *command, int **pipes, int i);

#endif