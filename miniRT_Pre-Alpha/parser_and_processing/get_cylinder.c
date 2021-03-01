/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:27:47 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/30 22:42:23 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_CYLINDER);
	while (**str == ' ')
		(*str)++;
}

/*
** //printf("cam_create : %p\n", new_cam);
*/

static t_cylinder	*create_cylinder(t_vars *vars)
{
	t_cylinder		*new_cylinder;

	new_cylinder = malloc(sizeof(t_cylinder));
	if (new_cylinder == NULL)
		errorka(vars, NMA_CYLINDER);
	if (vars->objects.cylinder == NULL)
	{
		vars->objects.cylinder = new_cylinder;
		vars->objects.cylinder->next = NULL;
	}
	else
	{
		while (vars->objects.cylinder->next != NULL)
			vars->objects.cylinder = vars->objects.cylinder->next;
		vars->objects.cylinder->next = new_cylinder;
		vars->objects.cylinder->next->next = NULL;
	}
	new_cylinder->color = 0;
	vars->need_cleared[CYLINDER] = 1;
	vars->cleared_func[CYLINDER] = free_cylinder;
	return (new_cylinder);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_cylinder(t_vars *vars, char *str)
{
	t_cylinder		*cylinder;

	cylinder = create_cylinder(vars);
	str += 2;
	skip_space(vars, &str);
	if (!get_coordinates(&str, cylinder->coordinates))
		errorka(vars, INCORRECT_CYLINDER);
	skip_space(vars, &str);
	if (!get_coordinates(&str, cylinder->normal_vector))
		errorka(vars, INCORRECT_CYLINDER);
	if (1 < cylinder->normal_vector[0] || cylinder->normal_vector[0] < -1 ||
		1 < cylinder->normal_vector[1] || cylinder->normal_vector[1] < -1 ||
		1 < cylinder->normal_vector[2] || cylinder->normal_vector[2] < -1)
		errorka(vars, INCORRECT_CYLINDER);
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &cylinder->diameter, INT_MIN + 1, INT_MAX))
		errorka(vars, INCORRECT_CYLINDER);
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &cylinder->height, INT_MIN + 1, INT_MAX))
		errorka(vars, INCORRECT_CYLINDER);
	skip_space(vars, &str);
	if (!add_rgb(&str, &cylinder->color))
		errorka(vars, INCORRECT_CYLINDER);
	if (*str != '\0')
		errorka(vars, INCORRECT_CYLINDER);
}
