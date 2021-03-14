/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_top_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:41:43 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:41:51 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			setup_top_p(t_vars *vars)
{
	t_img_data	data;

	data = vars->imgs.top_p;
	data.img = mlx_new_image(vars->mlx, 80, 80);
	data.addr = mlx_get_data_addr(data.img,
								&data.bit_per_pixel,
								&data.width,
								&data.endian);
	data.height = 80;
	fill_img(data, 0xff000000);
	vars->imgs.top_p = data;
	vars->need_cleared[TOP_P] = 1;
	vars->cleared_func[TOP_P] = free_top_p;
}
