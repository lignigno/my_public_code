/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:33:27 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/18 02:30:27 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_LIGHT);
	while (**str == ' ')
		(*str)++;
}

static t_light	*create_light(t_vars *vars)
{
	t_light		*new_light;
	t_light		*iterator;

	new_light = malloc(sizeof(t_light));
	if (new_light == NULL)
		errorka(vars, NMA_LIGHT);
	if (vars->objects.light == NULL)
	{
		vars->objects.light = new_light;
		vars->objects.light->next = NULL;
	}
	else
	{
		iterator = vars->objects.light;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_light;
		iterator->next->next = NULL;
	}
	new_light->color = 0;
	vars->need_cleared[LIGHT] = 1;
	vars->cleared_func[LIGHT] = free_light;
	return (new_light);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_light(t_vars *vars, char *str)
{
	t_light		*light;
	double		alpha;

	light = create_light(vars);
	str++;
	skip_space(vars, &str);
	if (!get_coordinates(&str, &light->coordinates))
		errorka(vars, INCORRECT_LIGHT);
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &alpha, 0, 1))
		errorka(vars, INCORRECT_LIGHT);
	light->color = IN_A_HUMAN_WAY ? (1 - alpha) * 255 : alpha * 255;
	skip_space(vars, &str);
	if (!add_rgb(&str, &light->color))
		errorka(vars, INCORRECT_LIGHT);
	if (*str != '\0')
		errorka(vars, INCORRECT_LIGHT);
}
