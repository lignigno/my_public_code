/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bckg_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:44:23 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:44:24 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

void	free_canvas(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.canvas.img);
}

void	free_top_p(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.top_p.img);
}

void	free_crt_p(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.crt_p.img);
}

void	free_adj_p(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.adj_p.img);
}
