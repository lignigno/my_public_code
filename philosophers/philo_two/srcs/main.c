/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:32:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 04:37:30 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	if (!wait_philosophers(v) || v->error)
		return (1);
	return (0);
}
