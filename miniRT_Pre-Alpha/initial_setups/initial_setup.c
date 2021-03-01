/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:55:06 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/13 05:34:48 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
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

static void		setup_variables(t_vars *vars)
{
	vars->w_win = 0;
	vars->h_win = 0;
	vars->ambient = 0;
	vars->save = 0;
	vars->x = vars->w_win / 2;	//pers
	vars->y = vars->h_win / 2;	//pers
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
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			initial_setup(t_vars *vars, int count, char **value)
{
	int			width;
	int			height;

	setup_variables(vars);
	setup_objects(vars);
	processing_input_values(vars, count, value);
	parser_scene_file(vars, value[1]);
	//maybe validate input params
	mlx_get_screen_size(vars->mlx, &width, &height);
	vars->w_win = vars->w_win < width ? vars->w_win : width;
	vars->h_win = vars->h_win < height ? vars->h_win : height;
	setup_structs(vars);
}
