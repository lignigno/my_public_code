/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters_with_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 06:35:28 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/26 08:59:15 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static int		intersection(t_plane *plane,
							t_vector p_1,
							t_vector p_2,
							t_inter *point)
{
	double		var;
	double		divisor;

	p_2 = sum_vector(p_2, -1, p_1);
	divisor = (plane->normal_vector.x * p_2.x +
				plane->normal_vector.y * p_2.y +
				plane->normal_vector.z * p_2.z);
	if (-0.000000000001 < divisor && divisor < 0.000000000001)
		return (0);
	var = -(plane->normal_vector.x * p_1.x + plane->normal_vector.y * p_1.y +
			plane->normal_vector.z * p_1.z -
			plane->normal_vector.x * plane->coordinates.x -
			plane->normal_vector.y * plane->coordinates.y -
			plane->normal_vector.z * plane->coordinates.z) / divisor;
	if (var < 0.0000001)
		return (0);
	p_1 = sum_vector(p_1, 1, multiplying_vector(p_2, var));
	point->point = p_1;
	point->obj.plane = plane;
	point->color = plane->color;
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

t_inter			inters_with_plane(t_vars *vars, t_vector p_1, t_vector p_2)
{
	t_inter		point;
	t_inter		result;
	t_plane		*iterator;

	result.point.x = NAN;
	result.obj.plane = NULL;
	iterator = vars->objects.plane;
	while (iterator != NULL)
	{
		if (intersection(iterator, p_1, p_2, &point))
			if (closer(point.point, result.point, p_1))
				result = point;
		iterator = iterator->next;
	}
	result.obj.sphere = NULL;
	result.obj.square = NULL;
	result.obj.cylinder = NULL;
	result.obj.triangle = NULL;
	return (result);
}
