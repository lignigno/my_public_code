/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_chairs_at_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:52:01 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/07 20:40:05 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// _________________________________________________________________SUBFUNCTIONS

static t_chair	*bring_another_chair(t_chair *table, int digit, t_v *v)
{
	t_chair	*another_chair;
	t_chair	*iterator;

	another_chair = malloc(sizeof(t_chair));
	if (!another_chair)
		return ((t_chair *)((long)0 * errorka_0("we've ended of chairs", 0)));
	another_chair->v = v;
	another_chair->count = 0;
	another_chair->philo = 0;
	another_chair->left_chair = NULL;
	another_chair->right_chair = NULL;
	another_chair->seat_number = digit;
	if (!table)
		return (another_chair);
	iterator = table;
	while (iterator->right_chair)
		iterator = iterator->right_chair;
	iterator->right_chair = another_chair;
	another_chair->left_chair = iterator;
	return (table);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	connect_ends(t_chair *list)
{
	t_chair	*iterator;

	iterator = list;
	while (iterator->right_chair)
		iterator = iterator->right_chair;
	iterator->right_chair = list;
	list->left_chair = iterator;
}

// ____________________________________________________________________MAIN FUNC

int	put_chairs_at_table(t_v *v)
{
	size_t	i;
	t_chair	*result;
	t_chair	*last_result;

	result = NULL;
	i = 0;
	while (i < v->count_of_philo)
	{
		last_result = result;
		result = bring_another_chair(result, i + 1, v);
		if (!result)
		{
			v->error = 1;
			v->table = last_result;
			return (0);
		}
		i++;
	}
	connect_ends(result);
	v->table = result;
	return (1);
}
