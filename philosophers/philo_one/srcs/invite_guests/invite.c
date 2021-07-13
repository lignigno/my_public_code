/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:19:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/13 03:25:06 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// _________________________________________________________________SUBFUNCTIONS

static void	eating(t_chair *place, size_t *last_eating)
{
	pthread_mutex_lock(&place->left_fork);
	logs(place->v, place->seat_number, "has taken a left fork");
	pthread_mutex_lock(&place->right_fork);
	logs(place->v, place->seat_number, "has taken a right fork");
	if (get_time() - *last_eating > ((t_v *)place->v)->time_to_die)
		errorka_2(place->v, place->seat_number);
	logs(place->v, place->seat_number, "is eating");
	*last_eating = get_time();
	while (get_time() - *last_eating < ((t_v *)place->v)->time_to_eat)
	{
		if (get_time() - *last_eating > ((t_v *)place->v)->time_to_die)
			errorka_2(place->v, place->seat_number);
		usleep(500);
	}
	place->count++;
	pthread_mutex_unlock(&place->left_fork);
	pthread_mutex_unlock(&place->right_fork);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	*philo_life(void *var)
{
	size_t	start;
	t_chair	*place;
	size_t	last_eating;

	place = var;
	last_eating = ((t_v *)place->v)->start_time;
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
	return (NULL);
}

// ____________________________________________________________________MAIN FUNC

int	invite_guests_to_the_table(t_v *v)
{
	t_chair	*iterator;
	int		status;
	size_t	i;

	iterator = v->table;
	v->start_time = get_time();
	i = 0;
	while (i < v->count_of_philo)
	{
		status = pthread_create(&iterator->philo, NULL, philo_life, iterator);
		if (status)
		{
			pthread_mutex_lock(&v->write_mutex);
			return (errorka_0("pthread_create broke", 0));
		}
		iterator = iterator->right_chair;
		i++;
	}
	return (1);
}
