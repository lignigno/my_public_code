/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cams_views.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:42:48 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:42:49 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			setup_cams_views(t_vars *vars)
{
	t_cam		*iterator;

	iterator = vars->objects.cam;
	while (iterator != NULL)
	{
		iterator->view.img = mlx_new_image(vars->mlx, vars->w_win, vars->h_win);
		iterator->view.addr = mlx_get_data_addr(iterator->view.img,
												&iterator->view.bit_per_pixel,
												&iterator->view.width,
												&iterator->view.endian);
		iterator->view.height = vars->h_win;
		iterator = iterator->next;
	}
	vars->need_cleared[CAM_IMG] = 1;
}
