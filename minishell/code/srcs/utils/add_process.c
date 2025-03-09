/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 08:52:52 by rquenten          #+#    #+#             */
/*   Updated: 2021/06/01 08:55:26 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	add_process(t_all_var *all, t_command *command, int pid)
{
	t_processes	*new_process;
	t_processes	*iterator;

	new_process = malloc(sizeof(t_processes));
	if (!new_process)
		errorka(all, NMA_EXECUTE);
	new_process->name = command->argv[0];
	new_process->pid = pid;
	new_process->next = NULL;
	if (!g_processes)
	{
		g_processes = new_process;
		return ;
	}
	iterator = g_processes;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new_process;
}
