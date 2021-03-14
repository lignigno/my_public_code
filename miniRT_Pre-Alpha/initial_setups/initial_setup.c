/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:55:06 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:37:41 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
**
** <<<<<<<<[FOR_SETUP_VARIABLES]>>>>>>>>
*/

static void		setup_need_cleared(t_vars *vars)
{
	int i;

	i = 0;
	while (i < 21)
		vars->need_cleared[i++] = 0;
}

static void		setup_mlx(t_vars *vars)
{
	vars->mlx = NULL;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		errorka(vars, NOT_CREATED_MLX);
	vars->need_cleared[MLX] = 1;
	vars->cleared_func[MLX] = free_mlx;
}

/*
** <<<<<<<<[SUBFUNCTIONS]>>>>>>>>
*/

static void		setup_variables(t_vars *vars)
{
	vars->w_win = 0;
	vars->h_win = 0;
	vars->ambient = 0;
	vars->screen_saver = 1;
	vars->win = NULL;
	setup_need_cleared(vars);
	setup_mlx(vars);
}

static void		setup_structs(t_vars *vars)
{
	setup_canvas(vars);
	setup_top_p(vars);
	setup_crt_p(vars);
	if (ADJUSTMENTS)
		setup_adj_p(vars);
	setup_cams_views(vars);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			initial_setup(t_vars *vars, char **value)
{
	int			width;
	int			height;

	setup_variables(vars);
	setup_objects(vars);
	parser_scene_file(vars, value[1]);
	mlx_get_screen_size(vars->mlx, &width, &height);
	vars->w_win = vars->w_win < width ? vars->w_win : width;
	vars->h_win = vars->h_win < height ? vars->h_win : height;
	vars->win = mlx_new_window(vars->mlx, vars->w_win, vars->h_win, "UGame...");
	setup_structs(vars);
}
