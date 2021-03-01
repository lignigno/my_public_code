/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:30:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/30 22:13:19 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*d
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_SPHERE);
	while (**str == ' ')
		(*str)++;
}

/*
** //printf("cam_create : %p\n", new_cam);
*/

static t_sphere	*create_sphere(t_vars *vars)
{
	t_sphere		*new_sphere;
	new_sphere = malloc(sizeof(t_sphere));
	if (new_sphere == NULL)
		errorka(vars, NMA_SPHERE);
	if (vars->objects.sphere == NULL)
	{
		vars->objects.sphere = new_sphere;
		vars->objects.sphere->next = NULL;
	}
	else
	{
		while (vars->objects.sphere->next != NULL)
			vars->objects.sphere = vars->objects.sphere->next;
		vars->objects.sphere->next = new_sphere;
		vars->objects.sphere->next->next = NULL;
	}
	new_sphere->color = 0;
	new_sphere->diameter = 0.0;
	vars->need_cleared[SPHERE] = 1;
	vars->cleared_func[SPHERE] = free_sphere;
	return (new_sphere);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_sphere(t_vars *vars, char *str)
{
	t_sphere		*sphere;

	sphere = create_sphere(vars);
	str += 2;
	skip_space(vars, &str);
	if (!get_coordinates(&str, sphere->coordinates))
		errorka(vars, INCORRECT_SPHERE);
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &sphere->diameter, INT_MIN + 1, INT_MAX))
		errorka(vars, INCORRECT_SPHERE);
	skip_space(vars, &str);
	if (!add_rgb(&str, &sphere->color))
		errorka(vars, INCORRECT_SPHERE);
	if (*str != '\0')
		errorka(vars, INCORRECT_SPHERE);
}
