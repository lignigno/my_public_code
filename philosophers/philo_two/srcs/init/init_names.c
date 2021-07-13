/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 01:56:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 04:18:01 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// ____________________________________________________________________MAIN FUNC

int	init_names(t_v *v)
{
	v->names = malloc(COUNT_NAMES * sizeof(char *));
	if (!v->names)
	{
		v->error = errorka_0("can't create array of names", 1);
		return (0);
	}
	v->names[WRITE_SEM] = "write_sem";
	v->names[TRAY_FOR_FORKS] = "tray_for_forks";
	return (1);
}
