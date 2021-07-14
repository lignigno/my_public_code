/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:11:28 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 04:48:38 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// __________________________________________________________________SUBFUNCTION

static int	wait_philosophers(t_v *v)
{
	t_chair	*iterator;
	int		count_philo;
	int		count_philo_ready;

	iterator = v->table;
	count_philo_ready = 0;
	count_philo = ((t_chair *)v->table->left_chair)->seat_number;
	while (v->each_must_eat > 0)
	{
		if (iterator->count == v->each_must_eat)
			count_philo_ready++;
		if (count_philo_ready == count_philo)
			return (finish(v, iterator->seat_number));
		iterator = iterator->right_chair;
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
