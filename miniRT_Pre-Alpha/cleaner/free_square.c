/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:44:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:15:12 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_square : %p\n", square);
*/

void			free_square(t_vars *vars)
{
	t_square	*square;
	t_square	*next;

	square = vars->objects.square;
	while (square != NULL)
	{
		next = square->next;
		free(square);
		square = next;
	}
}
