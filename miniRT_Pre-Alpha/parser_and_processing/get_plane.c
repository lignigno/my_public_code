/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:06:09 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/30 03:32:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_PLANE);
	while (**str == ' ')
		(*str)++;
}

/*
** //printf("cam_create : %p\n", new_cam);
*/

static t_plane	*create_plane(t_vars *vars)
{
	t_plane		*new_plane;
	new_plane = malloc(sizeof(t_plane));
	if (new_plane == NULL)
		errorka(vars, NMA_PLANE);
	if (vars->objects.plane == NULL)
	{
		vars->objects.plane = new_plane;
		vars->objects.plane->next = NULL;
	}
	else
	{
		while (vars->objects.plane->next != NULL)
			vars->objects.plane = vars->objects.plane->next;
		vars->objects.plane->next = new_plane;
		vars->objects.plane->next->next = NULL;
	}
	new_plane->color = 0;
	vars->need_cleared[PLANE] = 1;
	vars->cleared_func[PLANE] = free_plane;
	return (new_plane);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_plane(t_vars *vars, char *str)
{
	t_plane		*plane;

	plane = create_plane(vars);
	str += 2;
	skip_space(vars, &str);
	if (!get_coordinates(&str, plane->coordinates))
		errorka(vars, INCORRECT_PLANE);
	skip_space(vars, &str);
	if (!get_coordinates(&str, plane->normal_vector))
		errorka(vars, INCORRECT_PLANE);
	if (1 < plane->normal_vector[0] || plane->normal_vector[0] < -1 ||
		1 < plane->normal_vector[1] || plane->normal_vector[1] < -1 ||
		1 < plane->normal_vector[2] || plane->normal_vector[2] < -1)
		errorka(vars, INCORRECT_PLANE);
	skip_space(vars, &str);
	if (!add_rgb(&str, &plane->color))
		errorka(vars, INCORRECT_PLANE);
	if (*str != '\0')
		errorka(vars, INCORRECT_PLANE);
}
