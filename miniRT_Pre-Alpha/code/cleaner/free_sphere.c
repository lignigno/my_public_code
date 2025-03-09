/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:45:24 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:14:41 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_sphere : %p\n", sphere);
*/

void			free_sphere(t_vars *vars)
{
	t_sphere	*sphere;
	t_sphere	*next;

	sphere = vars->objects.sphere;
	while (sphere != NULL)
	{
		next = sphere->next;
		free(sphere);
		sphere = next;
	}
}
