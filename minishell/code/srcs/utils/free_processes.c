/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:52:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 23:55:54 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	free_processes(void)
{
	t_processes	*iterator;
	t_processes	*tmp;

	iterator = g_processes;
	while (iterator)
	{
		tmp = iterator;
		iterator = iterator->next;
		free(tmp);
	}
	g_processes = NULL;
}
