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

static void		free_cam_img(t_vars *vars)
{
	t_cam		*iterator;

	iterator = vars->objects.cam;
	while (iterator != NULL)
	{
		mlx_destroy_image(vars->mlx, iterator->view.img);
		iterator = iterator->next;
	}
}

void			free_cam(t_vars *vars)
{
	t_cam		*cam;
	t_cam		*next;

	if (vars->need_cleared[CAM_IMG])
		free_cam_img(vars);
	cam = vars->objects.cam;
	while (cam != NULL)
	{
		next = cam->next;
		free(cam);
		cam = next;
	}
}
