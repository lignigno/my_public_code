/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_with_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:18 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:58:18 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static void	add_forward(t_env *new, t_env **list)
{
	new->next = *list;
	*list = new;
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	find_place(t_env *iterator, t_env *new)
{		
	while (iterator->next)
	{
		if (ft_strcmp(new->variable, ((t_env *)iterator->next)->variable) < 0)
		{
			new->next = iterator->next;
			iterator->next = new;
			return ;
		}
		iterator = (t_env *)iterator->next;
	}
	iterator->next = new;
}

// ________________________________________________________________MAIN FUNCTION

void	add_with_sorting(t_all_var *all, char *str, t_env **list)
{
	t_env	*new;
	t_env	*iterator;

	new = new_env(all, str);
	if (get_variable(*list, new->variable))
		if (change_existing_variable(all, new, *list))
			return ;
	new->next = NULL;
	iterator = *list;
	if (!*list)
		*list = new;
	else if (ft_strcmp(new->variable, iterator->variable) < 0)
		add_forward(new, list);
	else
		find_place(iterator, new);
}
