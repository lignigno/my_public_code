/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:35:34 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/13 05:48:34 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

void	initial_rendering(t_vars *vars)
{
	fill_img(vars->imgs.canvas, BCKG_CANVAS);
	//get_views_of_cams();

	//this mine
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.canvas.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tmp, 0, 0);
	ts_pers(vars);
}
