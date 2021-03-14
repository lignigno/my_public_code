/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_canvas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:22:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:42:09 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			setup_canvas(t_vars *vars)
{
	t_img_data	data;

	data = vars->imgs.canvas;
	data.img = mlx_new_image(vars->mlx, vars->w_win, vars->h_win);
	data.addr = mlx_get_data_addr(data.img,
								&data.bit_per_pixel,
								&data.width,
								&data.endian);
	data.height = vars->h_win;
	vars->imgs.canvas = data;
	vars->need_cleared[CANVAS] = 1;
	vars->cleared_func[CANVAS] = free_canvas;
}
