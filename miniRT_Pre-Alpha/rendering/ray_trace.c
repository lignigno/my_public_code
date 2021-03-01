/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:16:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/26 15:41:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

static int		find_point_intersection(t_vars *vars,
										t_vector p_1,
										t_vector p_2,
										t_inter *intersection)
{
	int			i;
	int			result;
	t_inter		points_intersection[5];

	points_intersection[0] = inters_with_plane(vars, p_1, p_2);
	points_intersection[1] = inters_with_sphere(vars, p_1, p_2);
	points_intersection[2] = inters_with_square(vars, p_1, p_2);
	points_intersection[3] = inters_with_cylinder(vars, p_1, p_2);
	points_intersection[4] = inters_with_triangle(vars, p_1, p_2);
	i = 0;
	result = 0;
	while (i < 5)
	{
		if (points_intersection[i].point.x == points_intersection[i].point.x)
			if (closer(points_intersection[i].point, intersection->point, p_1))
			{
				*intersection = points_intersection[i];
				result = 1;
			}
		i++;
	}
	return (result);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

int				ray_trace(t_vars *vars, t_vector p_1, t_vector p_2, int depth)
{
	int			color;
	t_inter		point_intersection;

	depth = 0;
	point_intersection.point.x = NAN;
	if (!find_point_intersection(vars, p_1, p_2, &point_intersection))
		return (BCKG_SCENE);
	color = shadow_ray(vars, point_intersection, p_1);
	return (color);
}
