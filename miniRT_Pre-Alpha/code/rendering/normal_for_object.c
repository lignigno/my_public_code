/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_for_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:18:15 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:18:16 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

t_vector		normal_for_plane(t_plane plane, t_vector start)
{
	double		cosin;

	start = sum_vector(start, -1, plane.coordinates);
	cosin = cos_vectors(plane.normal_vector, start);
	if (cosin < 0)
		return (multiplying_vector(plane.normal_vector, -1));
	return (plane.normal_vector);
}

t_vector		normal_for_sphere(t_inter intersection, t_vector start)
{
	t_vector	normal_vector;

	start = sum_vector(start, -1, intersection.obj.sphere->coordinates);
	if (intersection.obj.sphere->diameter / 2 >= len_vector(start))
		normal_vector = sum_vector(intersection.obj.sphere->coordinates, -1,
									intersection.point);
	else
		normal_vector = sum_vector(intersection.point, -1,
									intersection.obj.sphere->coordinates);
	return (normal_vector);
}

t_vector		normal_for_square(t_square square, t_vector start)
{
	double		cosin;

	start = sum_vector(start, -1, square.coordinates);
	cosin = cos_vectors(square.normal_vector, start);
	if (cosin < 0)
		return (multiplying_vector(square.normal_vector, -1));
	return (square.normal_vector);
}

t_vector		normal_for_cylinder(t_inter intersection, t_vector start)
{
	t_vector	normal_vector;

	start = sum_vector(start, -1, intersection.point);
	intersection.point = sum_vector(intersection.point,
						-1, intersection.obj.cylinder->coordinates);
	normal_vector = sum_vector(intersection.point,
	-scalar(intersection.point, intersection.obj.cylinder->orientation),
	intersection.obj.cylinder->orientation);
	return (normal_vector);
}

t_vector		normal_for_triangle(t_triangle triangle, t_vector start)
{
	double		cosin;

	start = sum_vector(start, -1, triangle.a);
	cosin = cos_vectors(triangle.normal_vector, start);
	if (cosin < 0)
		return (multiplying_vector(triangle.normal_vector, -1));
	return (triangle.normal_vector);
}
