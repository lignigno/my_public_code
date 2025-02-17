/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_my_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 08:51:42 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/01 23:12:34 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int	o_my_wait(void)
{
	t_processes	*iterator;
	int			status;

	status = 0;
	iterator = g_processes;
	while (iterator)
	{
		waitpid(iterator->pid, &status, WUNTRACED);
		iterator = iterator->next;
	}
	return (status);
}
