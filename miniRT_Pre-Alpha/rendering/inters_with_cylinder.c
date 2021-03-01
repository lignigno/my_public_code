/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters_with_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:04:58 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:10:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

/*
** scalar(cylinder.orientation,
** 	sum_vector(p_inter_2, -1, top)) < 0.0 &&
** scalar(cylinder.orientation,
** 	sum_vector(p_inter_2, -1, cylinder.coordinates)) > 0.0
*/

static int		sub_func_for_norm(t_cylinder cylinder,
									t_vector p_inter_1,
									t_vector top)
{
	if (scalar(cylinder.orientation,
				sum_vector(p_inter_1, -1, top)) < 0.0 &&
			scalar(cylinder.orientation,
				sum_vector(p_inter_1, -1, cylinder.coordinates)) > 0.0)
		return (1);
	return (0);
}

static void		find_closer_point_intersection(t_cylinder cylinder,
												t_vector p_1,
												t_vector p_2,
												t_inter *point_intersection)
{
	t_vector	top;
	t_vector	p_inter_1;
	t_vector	p_inter_2;

	p_2 = sum_vector(p_2, -1, p_1);
	p_inter_1 = multiplying_vector(p_2, point_intersection->point.x);
	p_inter_2 = multiplying_vector(p_2, point_intersection->point.y);
	p_inter_1 = sum_vector(p_inter_1, 1, p_1);
	p_inter_2 = sum_vector(p_inter_2, 1, p_1);
	top = multiplying_vector(cylinder.orientation,
			cylinder.height / len_vector(cylinder.orientation));
	if (point_intersection->point.x > 0.0000001 &&
		point_intersection->point.y > 0.0000001)
		if (closer(p_inter_1, p_inter_2, p_1) &&
		sub_func_for_norm(cylinder, p_inter_1, top))
			point_intersection->point = p_inter_1;
		else
			point_intersection->point = p_inter_2;
	else if (point_intersection->point.x > 0.0000001)
		point_intersection->point = p_inter_1;
	else if (point_intersection->point.y > 0.0000001)
		point_intersection->point = p_inter_2;
	else
		point_intersection->point.x = NAN;
}

static t_vector	get_coefficient(t_cylinder cylinder, t_vector p_1, t_vector p_2)
{
	t_vector	vectors[4];
	t_vector	result;

	vectors[0] = sum_vector(p_2, -1, p_1);
	vectors[3] = sum_vector(p_1, -1, cylinder.coordinates);
	vectors[1] = multiplying_vector(cylinder.orientation,
						scalar(vectors[0], cylinder.orientation));
	vectors[1] = sum_vector(vectors[1], -1, vectors[0]);
	vectors[2] = multiplying_vector(cylinder.orientation,
						scalar(vectors[3], cylinder.orientation));
	vectors[2] = sum_vector(vectors[2], -1, vectors[3]);
	result.x = scalar(vectors[1], vectors[1]);
	result.y = 2 * scalar(vectors[1], vectors[2]);
	result.z = scalar(vectors[2], vectors[2]);
	result.z -= (cylinder.diameter / 2) * (cylinder.diameter / 2);
	return (result);
}

static int		intersection(t_cylinder *cylinder,
							t_vector p_1,
							t_vector p_2,
							t_inter *inter)
{
	t_vector	top;
	t_vector	coef;
	double		discriminant;

	coef = get_coefficient(*cylinder, p_1, p_2);
	discriminant = coef.y * coef.y - 4 * coef.x * coef.z;
	if (discriminant < 0)
		return (0);
	inter->point.x = (-coef.y - sqrt(discriminant)) / (2 * coef.x);
	inter->point.y = (-coef.y + sqrt(discriminant)) / (2 * coef.x);
	find_closer_point_intersection(*cylinder, p_1, p_2, inter);
	if (inter->point.x != inter->point.x)
		return (0);
	top = multiplying_vector(cylinder->orientation,
				cylinder->height / len_vector(cylinder->orientation));
	if (scalar(cylinder->orientation,
			sum_vector(inter->point, -1, top)) > 0.0 ||
		scalar(cylinder->orientation,
			sum_vector(inter->point, -1, cylinder->coordinates)) < 0.0)
		return (0);
	inter->obj.cylinder = cylinder;
	inter->color = cylinder->color;
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

t_inter			inters_with_cylinder(t_vars *vars, t_vector p_1, t_vector p_2)
{
	t_inter		point;
	t_inter		result;
	t_cylinder	*iterator;

	result.point.x = NAN;
	result.obj.cylinder = NULL;
	iterator = vars->objects.cylinder;
	while (iterator != NULL)
	{
		if (intersection(iterator, p_1, p_2, &point))
			if (closer(point.point, result.point, p_1))
				result = point;
		iterator = iterator->next;
	}
	result.obj.plane = NULL;
	result.obj.sphere = NULL;
	result.obj.square = NULL;
	result.obj.triangle = NULL;
	return (result);
}
