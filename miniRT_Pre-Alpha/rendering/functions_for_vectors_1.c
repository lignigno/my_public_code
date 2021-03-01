/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_vectors_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:41:39 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:17:58 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** FUNCTION NAME_:____________________________________________________LEN VECTOR
** ________________________________________________________________MAIN FUNCTION
*/

double			len_vector(t_vector vector)
{
	double		len;

	len = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	return (len);
}

/*
** FUNCTION NAME_:____________________________________________________SUM VECTOR
** ________________________________________________________________MAIN FUNCTION
*/

t_vector		sum_vector(t_vector vector_1, double sign, t_vector vector_2)
{
	vector_1.x += sign * vector_2.x;
	vector_1.y += sign * vector_2.y;
	vector_1.z += sign * vector_2.z;
	return (vector_1);
}

/*
** FUNCTION NAME_:____________________________________________MULTIPLYING VECTOR
** ________________________________________________________________MAIN FUNCTION
*/

t_vector		multiplying_vector(t_vector vector, double num)
{
	vector.x *= num;
	vector.y *= num;
	vector.z *= num;
	return (vector);
}

/*
** FUNCTION NAME_:_______________________________________________VECTOR ROTATION
** ________________________________________________________________MAIN FUNCTION
*/

t_vector		vector_rotate(t_vector vector, t_vector axis, double angle)
{
	double		matrix[3][3];
	double		cos_angle;
	double		sin_angle;
	t_vector	new_vector;

	cos_angle = cos(angle * M_PI / 180);
	sin_angle = sin(angle * M_PI / 180);
	matrix[0][0] = cos_angle + (1 - cos_angle) * axis.x * axis.x;
	matrix[0][1] = (1 - cos_angle) * axis.x * axis.y - sin_angle * axis.z;
	matrix[0][2] = (1 - cos_angle) * axis.x * axis.z + sin_angle * axis.y;
	matrix[1][0] = (1 - cos_angle) * axis.y * axis.x + sin_angle * axis.z;
	matrix[1][1] = cos_angle + (1 - cos_angle) * axis.y * axis.y;
	matrix[1][2] = (1 - cos_angle) * axis.y * axis.z - sin_angle * axis.x;
	matrix[2][0] = (1 - cos_angle) * axis.z * axis.x - sin_angle * axis.y;
	matrix[2][1] = (1 - cos_angle) * axis.z * axis.y + sin_angle * axis.x;
	matrix[2][2] = cos_angle + (1 - cos_angle) * axis.z * axis.z;
	new_vector.x = matrix[0][0] * vector.x + matrix[0][1] * vector.y +
											matrix[0][2] * vector.z;
	new_vector.y = matrix[1][0] * vector.x + matrix[1][1] * vector.y +
											matrix[1][2] * vector.z;
	new_vector.z = matrix[2][0] * vector.x + matrix[2][1] * vector.y +
											matrix[2][2] * vector.z;
	return (new_vector);
}

/*
** FUNCTION NAME_:_____________________________________CALCULATING NORMAL VECTOR
** ________________________________________________________________MAIN FUNCTION
*/

t_vector		calculating_normal_vector(t_vector orientation)
{
	t_vector	normal_vector;

	if (orientation.z == 0)
	{
		normal_vector.x = 0;
		normal_vector.y = 0;
		normal_vector.z = 1;
	}
	else
	{
		if (orientation.x == 0 && orientation.y == 0)
			normal_vector.x = 1;
		else
			normal_vector.x = orientation.x * (orientation.z < 0 ? 1 : -1);
		normal_vector.y = orientation.y * (orientation.z < 0 ? 1 : -1);
		normal_vector.z = sqrt(1 - orientation.z * orientation.z);
	}
	normal_vector = multiplying_vector(normal_vector,
										len_vector(normal_vector));
	return (normal_vector);
}
