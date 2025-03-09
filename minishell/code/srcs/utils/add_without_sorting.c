/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_without_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:27 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:58:28 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void	add_without_sorting(t_all_var *all, char *str, t_env **list)
{
	t_env	*iterator;
	t_env	*new;

	new = new_env(all, str);
	if (!new->value)
	{
		free(new->variable);
		free(new);
		return ;
	}
	if (get_variable(*list, new->variable))
		if (change_existing_variable(all, new, *list))
			return ;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return ;
	}
	iterator = *list;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new;
	iterator = (t_env *)iterator->next;
}
