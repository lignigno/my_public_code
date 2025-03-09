/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:47:37 by lignigno          #+#    #+#             */
/*   Updated: 2021/03/13 13:22:51 by lignigno         ###   ########.fr       */
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

int				key_event(int key, t_vars *vars)
{
	if (key == ESC)
		end_game(vars);
	if (key == SPACE)
	{
		if (vars->current_cam->next == NULL)
			vars->current_cam = vars->objects.cam;
		else
			vars->current_cam = vars->current_cam->next;
		main_render(vars, NO);
	}
	return (0);
}

/*
** // for_tools
**
** mlx_hook(vars->win, 4, 0, mouse_event, vars);
**
** int				mouse_event(int button, int x, int y, t_vars *vars)
** {
** 	vars->x = vars->x;
** 	printf("{button : %d}-{x : %d}-{y : %d}\n", button, x, y);
** 	return (0);
** }
*/

void			launch_minirt(t_vars *vars)
{
	if (vars->save)
	{
		create_bmp_img(vars);
		cleaner(vars);
		exit(0);
	}
	mlx_hook(vars->win, 2, 0, key_event, vars);
	mlx_hook(vars->win, 17, 0, end_game, vars);
	mlx_loop(vars->mlx);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

int				main(int count, char **value)
{
	t_vars		vars;

	processing_input_values(&vars, count, value);
	initial_setup(&vars, value);
	main_render(&vars, YES);
	launch_minirt(&vars);
	return (0);
}
