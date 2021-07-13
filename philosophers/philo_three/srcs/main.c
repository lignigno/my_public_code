/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 07:44:35 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/13 03:21:06 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// ____________________________________________________________________MAIN FUNC

int	main(int argc, char *argv[])
{
	t_v	*v;

	if (!checking_input_values(argc, argv))
		return (2);
	v = init(argc, argv);
	if (!v || v->error)
		return (1);
	if (!invite_guests_to_the_table(v))
		return (1);
	if (!wait_philosophers(v))
		return (1);
	return (0);
}
