/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:45:07 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:21:08 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		screen_saver(t_vars *vars)
{
	fill_img(vars->imgs.canvas, BCKG_CANVAS);
	mlx_put_image_to_window(vars->mlx, vars->win,
							vars->imgs.canvas.img,
							0, 0);
	mlx_string_put(vars->mlx, vars->win,
					vars->w_win / 2 - 20,
					vars->h_win / 2 - 5,
					0xff4fb4d8,
					"miniRT");
	mlx_string_put(vars->mlx, vars->win,
					vars->w_win / 2 - 40,
					vars->h_win / 2 + 5,
					0xff4fb4d8,
					"please wait...");
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			main_render(t_vars *vars, int full_render)
{
	if (full_render)
	{
		screen_saver(vars);
		render_cameras_views(vars);
		vars->screen_saver = 0;
		mlx_clear_window(vars->mlx, vars->win);
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
							vars->current_cam->view.img, 0, 0);
}
