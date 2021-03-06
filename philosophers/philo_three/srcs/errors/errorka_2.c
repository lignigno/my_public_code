/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:02:53 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/13 03:23:38 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

void	errorka_2(t_v *v, int seat_number)
{
	sem_wait(v->program_sem[WRITE_SEM]);
	write(2, ERROR_COLOR, ft_strlen(ERROR_COLOR));
	ft_putnbr(get_time() - v->start_time, 2);
	write(2, " ", 1);
	ft_putnbr(seat_number, 2);
	write(2, " died\033[m", 8);
	kill_philos(v, v->count_of_philo);
	sem_post(v->program_sem[IS_DEATH]);
	exit(2);
}
