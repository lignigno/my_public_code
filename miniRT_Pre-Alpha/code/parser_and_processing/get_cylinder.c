/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:27:47 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:34:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void			skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_CYLINDER);
	while (**str == ' ')
		(*str)++;
}

static t_cylinder	*create_cylinder(t_vars *vars)
{
	t_cylinder		*new_cylinder;
	t_cylinder		*iterator;

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
		iterator = vars->objects.cylinder;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_cylinder;
		iterator->next->next = NULL;
	}
	new_cylinder->color = 0;
	vars->need_cleared[CYLINDER] = 1;
	vars->cleared_func[CYLINDER] = free_cylinder;
	return (new_cylinder);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void				get_cylinder(t_vars *vars, char *str)
{
	t_cylinder		*cylinder;

	cylinder = create_cylinder(vars);
	skip_space(vars, &str);
	if (!get_coordinates(&str, &cylinder->coordinates))
		errorka(vars, INCORRECT_CYLINDER);
	skip_space(vars, &str);
	if (!get_coordinates(&str, &cylinder->orientation))
		errorka(vars, INCORRECT_CYLINDER);
	if (len_vector(cylinder->orientation) > 1 ||
		len_vector(cylinder->orientation) == 0)
		errorka(vars, INCORRECT_CYLINDER);
	cylinder->orientation = multiplying_vector(cylinder->orientation,
									1.0 / len_vector(cylinder->orientation));
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
