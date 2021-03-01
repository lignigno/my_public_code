/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 07:50:56 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/29 14:37:36 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

/*
** //printf("free_cam : %p\n", cam);
*/

void			free_cam(t_vars *vars)
{
	t_cam		*cam;
	t_cam		*next;

	cam = vars->objects.cam;
	while (cam != NULL)
	{
		next = cam->next;
		free(cam);
		cam = next;
	}
}
