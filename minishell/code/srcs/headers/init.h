/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:55:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:55:31 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "all_headers.h"

t_all_var	*init(char **env);
t_env		*init_env(t_all_var *all, char **env, int sorting);
void		init_logs(t_all_var *all, int count, char **value);
void		check_args(t_all_var *all, int count, char **value);

#endif
