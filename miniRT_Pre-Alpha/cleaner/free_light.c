/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:37:21 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:14:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_light : %p\n", light);
*/

void			free_light(t_vars *vars)
{
	t_light		*light;
	t_light		*next;

	light = vars->objects.light;
	while (light != NULL)
	{
		next = light->next;
		free(light);
		light = next;
	}
}
