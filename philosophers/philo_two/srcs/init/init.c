/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:50:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/07 21:37:41 by lignigno         ###   ########.fr       */
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
	if (!init_names(v))
		return (v);
	if (!init_programs_semaphors(v))
		return (v);
	if (!put_chairs_at_table(v))
		return (v);
	put_forks_in_tray(v);
	return (v);
}
