/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:11:28 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/20 21:03:27 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// __________________________________________________________________SUBFUNCTION

static int	wait_philosophers(t_v *v)
{
	while (v->each_must_eat > 0)
	{
		if (!v->count_of_philo)
			return (finish(v));
		usleep(500);
	}
	while (v->each_must_eat < 0)
		usleep(1000);
	return (0);
}

// ____________________________________________________________________MAIN FUNC

int	main(int argc, char *argv[])
{
	t_v	*v;

	if (!checking_input_values(argc, argv))
		return (1);
	v = init(argc, argv);
	if (!v || v->error)
		return (1);
	if (!invite_guests_to_the_table(v))
		return (1);
	if (!wait_philosophers(v))
		return (1);
	return (0);
}
