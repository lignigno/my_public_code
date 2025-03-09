/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:00:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:00:59 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

char	*get_value(t_all_var *all, char *variable)
{
	t_env	*iterator;

	if (!variable)
		return (NULL);
	iterator = all->env;
	while (iterator)
	{
		if (!ft_strcmp(iterator->variable, variable))
			return (iterator->value);
		iterator = iterator->next;
	}
	return (NULL);
}
