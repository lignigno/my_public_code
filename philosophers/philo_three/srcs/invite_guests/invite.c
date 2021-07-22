/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:19:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/22 16:26:13 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// _________________________________________________________________SUBFUNCTIONS

static void	eating(t_chair *place, size_t *last_eating)
{
	sem_wait(place->forks_tray);
	logs(place->v, place->seat_number, "has taken a fork");
	sem_wait(place->forks_tray);
	logs(place->v, place->seat_number, "has taken a fork");
	if (get_time() - *last_eating > ((t_v *)place->v)->time_to_die)
		errorka_2(place->v, place->seat_number);
	*last_eating = get_time();
	logs(place->v, place->seat_number, "is eating");
	while (get_time() - *last_eating < ((t_v *)place->v)->time_to_eat)
	{
		if (get_time() - *last_eating > ((t_v *)place->v)->time_to_die)
			errorka_2(place->v, place->seat_number);
		usleep(500);
	}
	if (++place->count == ((t_v *)place->v)->each_must_eat)
		sem_post(((t_v *)place->v)->program_sem[HAVE_EATEN]);
	sem_post(place->forks_tray);
	sem_post(place->forks_tray);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	philo_life(t_chair *place)
{
	size_t	start;
	size_t	last_eating;

	last_eating = get_time();
	if (place->seat_number % 2)
		eating(place, &last_eating);
	while (1)
	{
		start = get_time();
		logs(place->v, place->seat_number, "is sleeping");
		while (get_time() - start < ((t_v *)place->v)->time_to_sleep)
			usleep(500);
		logs(place->v, place->seat_number, "is thinking");
		eating(place, &last_eating);
	}
}

// ____________________________________________________________________MAIN FUNC

int	invite_guests_to_the_table(t_v *v)
{
	t_chair	*iterator;
	size_t	i;

	iterator = v->table;
	v->start_time = get_time();
	i = 0;
	while (i < v->count_of_philo)
	{
		v->pid[i] = fork();
		if (!v->pid[i])
			philo_life(iterator);
		else if (v->pid[i] < 0)
		{
			kill_philos(v, i);
			sem_wait(v->program_sem[WRITE_SEM]);
			return (errorka_0("fork broke", 0));
		}
		iterator = iterator->right_chair;
		i++;
	}
	return (1);
}
