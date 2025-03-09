/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:43:37 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:14:19 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_plane : %p\n", plane);
*/

void			free_plane(t_vars *vars)
{
	t_plane		*plane;
	t_plane		*next;

	plane = vars->objects.plane;
	while (plane != NULL)
	{
		next = plane->next;
		free(plane);
		plane = next;
	}
}
