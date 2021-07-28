/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fork_on_side.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:43:47 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/28 17:56:36 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// ____________________________________________________________________MAIN FUNC

int	put_fork_on_side(t_chair *table, int side)
{
	int		first_chair;
	int		status;
	t_chair	*iter;

	status = 0;
	first_chair = 0;
	iter = table;
	while (iter->seat_number != first_chair)
	{
		if (!first_chair)
			first_chair = iter->seat_number;
		if (side == LEFT)
		{
			iter->left_fork = malloc(sizeof(pthread_mutex_t));
			if (!iter->left_fork)
				return (0);
			status = pthread_mutex_init(iter->left_fork, NULL);
		}
		else
			iter->right_fork = ((t_chair *)iter->right_chair)->left_fork;
		if (status)
			return (0);
		iter = iter->right_chair;
	}
	return (!status);
}
