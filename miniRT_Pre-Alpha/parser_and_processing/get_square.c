/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:17:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 01:10:05 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_SQUARE);
	while (**str == ' ')
		(*str)++;
}

/*
** //printf("cam_create : %p\n", new_cam);
*/

static t_square	*create_square(t_vars *vars)
{
	t_square		*new_square;

	new_square = malloc(sizeof(t_square));
	if (new_square == NULL)
		errorka(vars, NMA_SQUARE);
	if (vars->objects.square == NULL)
	{
		vars->objects.square = new_square;
		vars->objects.square->next = NULL;
	}
	else
	{
		while (vars->objects.square->next != NULL)
			vars->objects.square = vars->objects.square->next;
		vars->objects.square->next = new_square;
		vars->objects.square->next->next = NULL;
	}
	new_square->color = 0;
	vars->need_cleared[SQUARE] = 1;
	vars->cleared_func[SQUARE] = free_square;
	return (new_square);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_square(t_vars *vars, char *str)
{
	t_square		*square;

	square = create_square(vars);
	str += 2;
	skip_space(vars, &str);
	if (!get_coordinates(&str, square->coordinates))
		errorka(vars, INCORRECT_SQUARE);
	skip_space(vars, &str);
	if (!get_coordinates(&str, square->normal_vector))
		errorka(vars, INCORRECT_SQUARE);
	if (1 < square->normal_vector[0] || square->normal_vector[0] < -1 ||
		1 < square->normal_vector[1] || square->normal_vector[1] < -1 ||
		1 < square->normal_vector[2] || square->normal_vector[2] < -1)
		errorka(vars, INCORRECT_SQUARE);
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &square->side_size, INT_MIN + 1, INT_MAX))
		errorka(vars, INCORRECT_SQUARE);
	skip_space(vars, &str);
	if (!add_rgb(&str, &square->color))
		errorka(vars, INCORRECT_SQUARE);
	if (*str != '\0')
		errorka(vars, INCORRECT_SQUARE);
}
