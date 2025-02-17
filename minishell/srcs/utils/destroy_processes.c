/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 08:35:44 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/01 23:00:24 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	destroy_processes(int signal, int except)
{
	while (g_processes)
	{
		if (g_processes->pid != except)
			kill(g_processes->pid, signal);
		g_processes = g_processes->next;
	}
}
