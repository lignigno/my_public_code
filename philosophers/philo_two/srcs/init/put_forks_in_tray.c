/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks_in_tray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 04:24:12 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/07 21:38:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// ____________________________________________________________________MAIN FUNC

void	put_forks_in_tray(t_v *v)
{
	int		first_chair;
	t_chair	*iter;
	size_t	i;

	i = 1;
	while (i < v->count_of_philo)
	{
		sem_post(v->program_sem[TRAY_FOR_FORKS]);
		i++;
	}
	i = 0;
	first_chair = 0;
	iter = v->table;
	while (iter->seat_number != first_chair)
	{
		if (!first_chair)
			first_chair = 1;
		iter->forks_tray = v->program_sem[TRAY_FOR_FORKS];
		iter = iter->right_chair;
		i++;
	}
}
