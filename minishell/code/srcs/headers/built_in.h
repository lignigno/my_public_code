/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:26 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 09:44:09 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "all_headers.h"

int		call_cd(t_all_var *all, t_command *command);
void	call_echo(t_command *command);
void	call_env(t_all_var *all);
void	call_exit(t_all_var *all);
int		call_export(t_all_var *all, t_command *command);
void	call_pwd(void);
void	unset(t_all_var *all, char *need_unset, t_env *exp, t_env *env);
int		call_unset(t_all_var *all, t_command *command);

#endif