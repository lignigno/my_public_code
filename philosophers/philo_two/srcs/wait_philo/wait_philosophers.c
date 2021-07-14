/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 02:07:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/13 03:22:07 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

// _________________________________________________________________SUBFUNCTIONS

static void	*track_death(void *v)
{
	sem_wait(((t_v *)v)->program_sem[IS_DEATH]);
	sem_wait(((t_v *)v)->program_sem[IS_DEATH]);
	((t_v *)v)->error = 1;
	return (NULL);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	*track_eaten(void *v)
{
	size_t	count;
	t_v		*vars;

	vars = v;
	sem_wait(vars->program_sem[HAVE_EATEN]);
	count = 0;
	while (1)
	{
		sem_wait(vars->program_sem[HAVE_EATEN]);
		count++;
		if (count == vars->count_of_philo)
		{
			finish(vars);
			vars->finish = 1;
		}
	}
	return (NULL);
}

// ____________________________________________________________________MAIN FUNC

int	wait_philosophers(t_v *v)
{
	pthread_t	death;
	pthread_t	eaten;
	int			status;

	status = pthread_create(&death, NULL, track_death, v);
	if (status)
	{
		sem_wait(v->program_sem[WRITE_SEM]);
		return (errorka_0("pthread_create death broke", 0));
	}
	if (v->each_must_eat > 0)
	{
		status = pthread_create(&eaten, NULL, track_eaten, v);
		if (status)
		{
			sem_wait(v->program_sem[WRITE_SEM]);
			return (errorka_0("pthread_create eaten broke", 0));
		}
	}
	while (!v->finish && !v->error)
		usleep(1000);
	return (1);
}
