/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:50:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 04:43:50 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// __________________________________________________________________SUBFUNCTION

static void	init_simple_variables(t_v *v, int argc, char *argv[])
{
	v->count_of_philo = sini(argv[1]);
	v->time_to_die = sini(argv[2]);
	v->time_to_eat = sini(argv[3]);
	v->time_to_sleep = sini(argv[4]);
	v->each_must_eat = -1;
	v->error = 0;
	if (argc > 5)
		v->each_must_eat = sini(argv[5]);
}

// ____________________________________________________________________MAIN FUNC

t_v	*init(int argc, char *argv[])
{
	t_v	*v;

	v = malloc(sizeof(t_v));
	if (!v)
		return ((t_v *)(errorka_0("failed to create main structure", 0)));
	init_simple_variables(v, argc, argv);
	if (pthread_mutex_init(&v->write_mutex, NULL))
	{
		v->error = errorka_0("the mutex was not initialized", 1);
		return (v);
	}
	if (!put_chairs_at_table(v))
		return (v);
	if (!put_fork_on_side(v->table, LEFT))
	{
		v->error = errorka_0("can't put fork on side", 1);
		return (v);
	}
	put_fork_on_side(v->table, RIGHT);
	return (v);
}
