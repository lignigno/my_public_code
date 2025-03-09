/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:01:05 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:01:05 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

t_env	*get_variable(t_env *list, char *name_variable)
{
	while (list)
	{
		if (!ft_strcmp(list->variable, name_variable))
			return (list);
		list = list->next;
	}
	return (list);
}
