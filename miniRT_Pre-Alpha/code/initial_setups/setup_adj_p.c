/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_adj_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:43:24 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:43:24 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void	setup_adj_p(t_vars *vars)
{
	t_img_data	data;

	data = vars->imgs.adj_p;
	data.img = mlx_new_image(vars->mlx, vars->w_win, vars->h_win);
	data.addr = mlx_get_data_addr(data.img,
								&data.bit_per_pixel,
								&data.width,
								&data.endian);
	vars->imgs.adj_p = data;
	vars->need_cleared[ADJ_P] = 1;
	vars->cleared_func[ADJ_P] = free_adj_p;
}
