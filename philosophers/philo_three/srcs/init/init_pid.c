/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 04:19:10 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 04:19:29 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// ____________________________________________________________________MAIN FUNC

int	init_pid(t_v *v)
{
	v->pid = malloc(v->count_of_philo * sizeof(int));
	if (!v->pid)
	{
		v->error = errorka_0("can't create array of pid", 1);
		return (0);
	}
	return (1);
}
