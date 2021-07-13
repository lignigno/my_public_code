/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:14:54 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/12 22:12:51 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// ____________________________________________________________________MAIN FUNC

void	kill_philos(t_v *v, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		kill(v->pid[i], SIGINT);
		i++;
	}
}