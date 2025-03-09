/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:46:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:15:29 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_triangle : %p\n", triangle);
*/

void			free_triangle(t_vars *vars)
{
	t_triangle	*triangle;
	t_triangle	*next;

	triangle = vars->objects.triangle;
	while (triangle != NULL)
	{
		next = triangle->next;
		free(triangle);
		triangle = next;
	}
}
