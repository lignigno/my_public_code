/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:47:37 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/13 05:48:26 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

int				end_game(t_vars *vars)
{
	cleaner(vars);
	exit(0);
	return (0);
}

void			ts_pers(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.top_p.img, vars->x, vars->y);
}

/*
** START__________________________________________________________________EVENTS
*/

int				key_event(int key, t_vars *vars)
{
	vars->x = key == LF ? vars->x - SPEED : vars->x;
	vars->x = key == RG ? vars->x + SPEED : vars->x;
	vars->y = key == DW ? vars->y + SPEED : vars->y;
	vars->y = key == UP ? vars->y - SPEED : vars->y;
	if (key == ESC)
		end_game(vars);
	//reaction_on_event(vars);
	initial_rendering(vars);
	return (0);
}

int				mouse_event(int button, int x, int y, t_vars *vars)
{
	vars->x = vars->x;
	printf("{button : %d}-{x : %d}-{y : %d}\n", button, x, y);
	return (0);
}

/*
** END____________________________________________________________________EVENTS
*/

void			launch_minirt(t_vars *vars)
{
	if (vars->save)
	{
		//logic for save :
		//
		//create bmp img
		//cleaner(vars);
		//exit (0);
	}
	mlx_hook(vars->win, 2, 0, key_event, vars);
	mlx_hook(vars->win, 4, 0, mouse_event, vars);
	mlx_hook(vars->win, 17, 0, end_game, vars);
	mlx_loop(vars->mlx);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

int				main(int count, char **value)
{
	t_vars		vars;
	int			width;
	int			height;

	initial_setup(&vars, count, value);
	vars.tmp = mlx_xpm_file_to_image(vars.mlx, "pp.xpm", &width, &height);
	//later to clean this rendering
	initial_rendering(&vars);
	launch_minirt(&vars);
	return (0);
}
