/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:44:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/11 21:04:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo_one.h"

# define LEFT 1
# define RIGHT 0

int	put_chairs_at_table(t_v *v);
int	put_fork_on_side(t_chair *table, int side);

#endif