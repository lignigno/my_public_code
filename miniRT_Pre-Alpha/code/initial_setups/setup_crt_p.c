/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_crt_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:48:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:43:17 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void	setup_crt_p(t_vars *vars)
{
	t_img_data	data;

	data = vars->imgs.crt_p;
	data.img = mlx_new_image(vars->mlx, vars->w_win, vars->h_win);
	data.addr = mlx_get_data_addr(data.img,
								&data.bit_per_pixel,
								&data.width,
								&data.endian);
	vars->imgs.crt_p = data;
	vars->need_cleared[CRT_P] = 1;
	vars->cleared_func[CRT_P] = free_crt_p;
}
