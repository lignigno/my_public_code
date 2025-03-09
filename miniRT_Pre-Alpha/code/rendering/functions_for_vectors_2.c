/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_vectors_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:43:47 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 21:58:02 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** FUNCTION NAME_:___________________________________________________COS VECTORS
** ________________________________________________________________MAIN FUNCTION
*/

double			cos_vectors(t_vector v1, t_vector v2)
{
	double		result;

	result = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) /
				(len_vector(v1) * len_vector(v2));
	return (result);
}

double			scalar(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
