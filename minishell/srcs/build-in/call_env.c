/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:50:59 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	call_env(t_all_var *all)
{
	t_env	*iterator;

	iterator = all->env;
	while (iterator)
	{
		write(1, iterator->variable, ft_strlen(iterator->variable));
		write(1, "=", 1);
		write(1, iterator->value, ft_strlen(iterator->value));
		write(1, "\n", 1);
		iterator = iterator->next;
	}
	exit(0);
}
