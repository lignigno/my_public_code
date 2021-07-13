/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program_semafors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 04:01:51 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/07 21:38:56 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// ____________________________________________________________________MAIN FUNC

int	init_programs_semaphors(t_v *v)
{
	int	i;

	v->program_sem = malloc(COUNT_NAMES * sizeof(sem_t **));
	if (!v->program_sem)
	{
		v->error = errorka_0("can't create array of semaphors", 1);
		return (0);
	}
	i = 0;
	while (i < COUNT_NAMES)
	{
		sem_unlink(v->names[i]);
		v->program_sem[i] = sem_open(v->names[i], O_CREAT, 0644, 1);
		if (v->program_sem[i] == SEM_FAILED)
		{
			v->error = errorka_0("can't create programs semafor", 1);
			return (0);
		}
		i++;
	}
	return (1);
}
