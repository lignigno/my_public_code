/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:46:07 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:13:13 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_cylinder : %p\n", cylinder);
*/

void			free_cylinder(t_vars *vars)
{
	t_cylinder	*cylinder;
	t_cylinder	*next;

	cylinder = vars->objects.cylinder;
	while (cylinder != NULL)
	{
		next = cylinder->next;
		free(cylinder);
		cylinder = next;
	}
}
