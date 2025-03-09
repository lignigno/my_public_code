/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters_with_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 06:33:33 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:20:20 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

static int		intersection_plane_square(t_square *square,
											t_vector p_1,
											t_vector p_2,
											t_vector *point)
{
	double		var;
	double		divisor;

	p_2 = sum_vector(p_2, -1, p_1);
	divisor = (square->normal_vector.x * p_2.x +
				square->normal_vector.y * p_2.y +
				square->normal_vector.z * p_2.z);
	if (-0.000000000001 < divisor && divisor < 0.000000000001)
		return (0);
	var = -(square->normal_vector.x * p_1.x + square->normal_vector.y * p_1.y +
			square->normal_vector.z * p_1.z -
			square->normal_vector.x * square->coordinates.x -
			square->normal_vector.y * square->coordinates.y -
			square->normal_vector.z * square->coordinates.z) / divisor;
	if (var > 0.0000001)
	{
		p_1 = sum_vector(p_1, 1, multiplying_vector(p_2, var));
		*point = p_1;
		return (1);
	}
	else
		return (0);
}

static int		intersection(t_square *square,
							t_vector p_1,
							t_vector p_2,
							t_inter *point)
{
	double		len;
	double		cosin;
	t_vector	inter;
	t_vector	vector_on_square;

	if (!intersection_plane_square(square, p_1, p_2, &inter))
		return (0);
	inter = sum_vector(inter, -1, square->coordinates);
	vector_on_square = calculating_normal_vector(square->normal_vector);
	len = len_vector(inter);
	cosin = cos_vectors(vector_on_square, inter);
	cosin *= cosin < 0 ? -1 : 1;
	if (square->side_size / 2 <= cosin * len ||
		square->side_size / 2 <= sqrt(1 - cosin * cosin) * len)
		return (0);
	inter = sum_vector(inter, 1, square->coordinates);
	point->point = inter;
	point->obj.square = square;
	point->color = square->color;
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

t_inter			inters_with_square(t_vars *vars, t_vector p_1, t_vector p_2)
{
	t_inter		point;
	t_inter		result;
	t_square	*iterator;

	result.point.x = NAN;
	result.obj.square = NULL;
	iterator = vars->objects.square;
	while (iterator != NULL)
	{
		if (intersection(iterator, p_1, p_2, &point))
			if (closer(point.point, result.point, p_1))
				result = point;
		iterator = iterator->next;
	}
	result.obj.plane = NULL;
	result.obj.sphere = NULL;
	result.obj.cylinder = NULL;
	result.obj.triangle = NULL;
	return (result);
}
