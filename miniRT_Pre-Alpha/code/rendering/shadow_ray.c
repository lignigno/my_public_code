/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:00:58 by lignigno          #+#    #+#             */
/*   Updated: 2021/03/13 08:17:58 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

static t_vector	convert_light(int light)
{
	int			alpha;
	int			light_color;
	double		illumination_level;
	t_vector	result;

	light_color = light & 0xffffff;
	alpha = 255 - ((light >> 24) & 0xff);
	illumination_level = alpha / 255.0;
	result.x = ((light & 0xff0000) >> 16) * illumination_level;
	result.y = ((light & 0xff00) >> 8) * illumination_level;
	result.z = (light & 0xff) * illumination_level;
	return (result);
}

static int		find_point_intersection(t_vars *vars,
										t_vector p_1,
										t_vector p_2)
{
	int			i;
	t_inter		points_intersection[5];

	points_intersection[0] = inters_with_plane(vars, p_1, p_2);
	points_intersection[1] = inters_with_sphere(vars, p_1, p_2);
	points_intersection[2] = inters_with_square(vars, p_1, p_2);
	points_intersection[3] = inters_with_cylinder(vars, p_1, p_2);
	points_intersection[4] = inters_with_triangle(vars, p_1, p_2);
	i = 0;
	while (i < 5)
	{
		if (points_intersection[i].point.x == points_intersection[i].point.x)
			if (closer(points_intersection[i].point, p_2, p_1))
				return (1);
		i++;
	}
	return (0);
}

static void		gradient_level(t_inter intersection,
								t_light light,
								t_vector *color,
								t_vector start)
{
	double		level;
	double		distans;
	t_vector	normal_vector;

	if (intersection.obj.plane != NULL)
		normal_vector = normal_for_plane(*intersection.obj.plane, start);
	if (intersection.obj.sphere != NULL)
		normal_vector = normal_for_sphere(intersection, start);
	if (intersection.obj.square != NULL)
		normal_vector = normal_for_square(*intersection.obj.square, start);
	if (intersection.obj.cylinder != NULL)
		normal_vector = normal_for_cylinder(intersection, start);
	if (intersection.obj.triangle != NULL)
		normal_vector = normal_for_triangle(*intersection.obj.triangle, start);
	light.coordinates = sum_vector(light.coordinates, -1, intersection.point);
	distans = len_vector(light.coordinates);
	level = cos_vectors(light.coordinates, normal_vector) /
				(A * distans * distans + B * distans + C);
	if (level > 0)
		*color = multiplying_vector(*color, level);
	else
		*color = multiplying_vector(*color, 0.0);
}

static t_vector	get_color_light(t_vars *vars,
								t_inter intersection,
								t_vector start)
{
	t_vector	current_color;
	t_vector	result_color;
	t_light		*iterator;

	iterator = vars->objects.light;
	result_color = convert_light(vars->ambient);
	while (iterator != NULL)
	{
		if (!find_point_intersection(vars, intersection.point,
											iterator->coordinates))
		{
			current_color = convert_light(iterator->color);
			gradient_level(intersection, *iterator, &current_color, start);
			result_color.x = (result_color.x + current_color.x) < 255 ?
								result_color.x + current_color.x : 255;
			result_color.y = (result_color.y + current_color.y) < 255 ?
								result_color.y + current_color.y : 255;
			result_color.z = (result_color.z + current_color.z) < 255 ?
								result_color.z + current_color.z : 255;
		}
		iterator = iterator->next;
	}
	return (result_color);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

int				shadow_ray(t_vars *vars, t_inter intersection, t_vector start)
{
	t_vector	light;
	int			new_color;

	light = get_color_light(vars, intersection, start);
	new_color = rgba(((intersection.color >> 16) & 0xff) * (light.x / 255),
					((intersection.color >> 8) & 0xff) * (light.y / 255),
					(intersection.color & 0xff) * (light.z / 255), 0);
	new_color = rgba(((new_color >> 16) & 0xff) + ((BCKG_SCENE >> 16) & 0xff),
					((new_color >> 8) & 0xff) + ((BCKG_SCENE >> 8) & 0xff),
					(new_color & 0xff) + (BCKG_SCENE & 0xff),
					((new_color >> 24) & 0xff) + ((BCKG_SCENE >> 24) & 0xff));
	return (new_color);
}
