/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters_with_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:19:14 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:19:49 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

static void		find_closer_point_intersection(t_vector p_1,
												t_vector p_2,
												t_inter *point_intersection)
{
	t_vector	point_intersection_1;
	t_vector	point_intersection_2;

	p_2 = sum_vector(p_2, -1, p_1);
	point_intersection_1 = multiplying_vector(p_2, point_intersection->point.x);
	point_intersection_2 = multiplying_vector(p_2, point_intersection->point.y);
	point_intersection_1 = sum_vector(point_intersection_1, 1, p_1);
	point_intersection_2 = sum_vector(point_intersection_2, 1, p_1);
	if (point_intersection->point.x > 0.0000001 &&
		point_intersection->point.y > 0.0000001)
	{
		if (closer(point_intersection_1, point_intersection_2, p_1))
			point_intersection->point = point_intersection_1;
		else
			point_intersection->point = point_intersection_2;
	}
	else if (point_intersection->point.x > 0.0000001)
		point_intersection->point = point_intersection_1;
	else if (point_intersection->point.y > 0.0000001)
		point_intersection->point = point_intersection_2;
	else
		point_intersection->point.x = NAN;
}

static int		intersection(t_sphere *sphere,
							t_vector p_1,
							t_vector p_2,
							t_inter *point)
{
	double		discriminant;
	t_vector	coef;
	t_vector	a;
	t_vector	b;

	a = sum_vector(p_1, -1, sphere->coordinates);
	b = sum_vector(p_2, -1, p_1);
	coef.x = b.x * b.x + b.y * b.y + b.z * b.z;
	coef.y = 2 * (a.x * b.x + a.y * b.y + a.z * b.z);
	coef.z = a.x * a.x + a.y * a.y + a.z * a.z;
	coef.z -= sphere->diameter / 2 * sphere->diameter / 2;
	discriminant = coef.y * coef.y - 4 * coef.x * coef.z;
	if (discriminant < 0)
		return (0);
	point->point.x = (-coef.y - sqrt(discriminant)) / (2 * coef.x);
	point->point.y = (-coef.y + sqrt(discriminant)) / (2 * coef.x);
	find_closer_point_intersection(p_1, p_2, point);
	if (point->point.x != point->point.x)
		return (0);
	point->obj.sphere = sphere;
	point->color = sphere->color;
	return (1);
}

t_inter			inters_with_sphere(t_vars *vars, t_vector p_1, t_vector p_2)
{
	t_inter		point;
	t_inter		result;
	t_sphere	*iterator;

	result.point.x = NAN;
	result.obj.sphere = NULL;
	iterator = vars->objects.sphere;
	while (iterator != NULL)
	{
		if (intersection(iterator, p_1, p_2, &point))
			if (closer(point.point, result.point, p_1))
				result = point;
		iterator = iterator->next;
	}
	result.obj.plane = NULL;
	result.obj.square = NULL;
	result.obj.cylinder = NULL;
	result.obj.triangle = NULL;
	return (result);
}
