/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters_with_triangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:39:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/03/13 14:11:01 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

static int		intersection_plane_triangle(t_triangle *triangle,
											t_vector p_1,
											t_vector p_2,
											t_vector *point)
{
	double		var;
	double		divisor;

	p_2 = sum_vector(p_2, -1, p_1);
	divisor = (triangle->normal_vector.x * p_2.x +
				triangle->normal_vector.y * p_2.y +
				triangle->normal_vector.z * p_2.z);
	if (-0.000000000001 < divisor && divisor < 0.000000000001)
		return (0);
	var = -(triangle->normal_vector.x * p_1.x +
			triangle->normal_vector.y * p_1.y +
			triangle->normal_vector.z * p_1.z -
			triangle->normal_vector.x * triangle->a.x -
			triangle->normal_vector.y * triangle->a.y -
			triangle->normal_vector.z * triangle->a.z) / divisor;
	if (var > 0.0000001)
	{
		p_1 = sum_vector(p_1, 1, multiplying_vector(p_2, var));
		*point = p_1;
		return (1);
	}
	else
		return (0);
}

static double	square_of_triangle(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (len_vector(c) / 2.0);
}

static int		in_triangle(t_triangle triangle, t_vector inter)
{
	t_vector	v1;
	t_vector	v2;
	double		s_of_main_tr;
	double		s_of_other_tr[3];

	v1 = sum_vector(triangle.a, -1, triangle.c);
	v2 = sum_vector(triangle.b, -1, triangle.c);
	triangle.a = sum_vector(triangle.a, -1, inter);
	triangle.b = sum_vector(triangle.b, -1, inter);
	triangle.c = sum_vector(triangle.c, -1, inter);
	s_of_main_tr = square_of_triangle(v1, v2);
	s_of_other_tr[0] = square_of_triangle(triangle.a, triangle.b);
	s_of_other_tr[1] = square_of_triangle(triangle.b, triangle.c);
	s_of_other_tr[2] = square_of_triangle(triangle.c, triangle.a);
	if (s_of_other_tr[0] + s_of_other_tr[1] +
		s_of_other_tr[2] > s_of_main_tr + 0.000000001)
		return (0);
	return (1);
}

static int		intersection(t_triangle *triangle,
							t_vector p_1,
							t_vector p_2,
							t_inter *point)
{
	t_vector	inter;
	t_vector	a;
	t_vector	b;

	a = triangle->a;
	b = triangle->b;
	a = sum_vector(a, -1, triangle->c);
	b = sum_vector(b, -1, triangle->c);
	triangle->normal_vector.x = a.y * b.z - a.z * b.y;
	triangle->normal_vector.y = a.z * b.x - a.x * b.z;
	triangle->normal_vector.z = a.x * b.y - a.y * b.x;
	if (!intersection_plane_triangle(triangle, p_1, p_2, &inter))
		return (0);
	if (!in_triangle(*triangle, inter))
		return (0);
	point->point = inter;
	point->obj.triangle = triangle;
	point->color = triangle->color;
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

t_inter			inters_with_triangle(t_vars *vars, t_vector p_1, t_vector p_2)
{
	t_inter		point;
	t_inter		result;
	t_triangle	*iterator;

	result.point.x = NAN;
	result.obj.triangle = NULL;
	iterator = vars->objects.triangle;
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
	result.obj.cylinder = NULL;
	return (result);
}
