/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cameras_views.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:54:37 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/26 13:31:33 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

static t_vector	move_on_row(t_vars *vars, t_cam *cam, t_vector vector, int row)
{
	double		height_scaling;
	t_vector	normal_vector;

	height_scaling = len_vector(cam->orientation);
	height_scaling *= (((double)cam->fov / vars->w_win) * M_PI / 180);
	height_scaling *= (vars->h_win / -2.0 + row);
	normal_vector = multiplying_vector(cam->normal_vector, height_scaling);
	vector = sum_vector(vector, 1, normal_vector);
	return (vector);
}

static void		write_percent(int part, int all)
{
	write(1, "\r", 1);
	write(1, "\033[35;1mrendered ", 16);
	ft_putnbr_fd((int)((double)part * 100 / all), 1);
	write(1, "%\033[35;1m", 9);
}

static void		render_view_for_cam(t_vars *vars, t_cam *cam)
{
	t_vector	new_orientation;
	int			column;
	int			row;
	double		x;

	cam->normal_vector = calculating_normal_vector(cam->orientation);
	row = -1;
	while (++row < vars->h_win)
	{
		column = 0;
		x = 0;
		while (x < cam->fov && cam->fov)
		{
			new_orientation = vector_rotate(cam->orientation,
								cam->normal_vector, cam->fov / -2 + x);
			new_orientation = move_on_row(vars, cam, new_orientation, row);
			new_orientation = sum_vector(new_orientation, 1, cam->coordinates);
			put_pixel(cam->view, column, row, ray_trace(vars,
								cam->coordinates, new_orientation, DEPTH));
			column++;
			x += (double)cam->fov / vars->w_win;
		}
		if (PERCENT)
			write_percent(row, vars->h_win - 1);
	}
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			render_cameras_views(t_vars *vars)
{
	int			cam_num;
	int			count_cam;
	t_cam		*cam;

	count_cam = 0;
	cam = vars->objects.cam;
	while (cam != NULL)
	{
		count_cam++;
		cam = cam->next;
	}
	cam_num = 1;
	cam = vars->objects.cam;
	while (cam != NULL)
	{
		write(1, "\033[36;1mCamera [", 15);
		ft_putnbr_fd(cam_num, 1);
		write(1, "\\", 1);
		ft_putnbr_fd(count_cam, 1);
		write(1, "]\033[0m\n", 6);
		render_view_for_cam(vars, cam);
		write(1, "\033[0m\n", 6);
		cam_num++;
		cam = cam->next;
	}
}
