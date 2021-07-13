/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:44:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 03:39:57 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo_three.h"

int		init_names(t_v *v);
int		init_pid(t_v *v);
int		init_programs_semaphors(t_v *v);
int		put_chairs_at_table(t_v *v);
void	put_forks_in_tray(t_v *v);

#endif