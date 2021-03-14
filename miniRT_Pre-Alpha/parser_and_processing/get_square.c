/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:17:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:34:49 by lignigno         ###   ########.fr       */
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

static t_square	*create_square(t_vars *vars)
{
	t_square		*new_square;
	t_square		*iterator;

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
		iterator = vars->objects.square;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_square;
		iterator->next->next = NULL;
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
	if (!get_coordinates(&str, &square->coordinates))
		errorka(vars, INCORRECT_SQUARE);
	skip_space(vars, &str);
	if (!get_coordinates(&str, &square->normal_vector))
		errorka(vars, INCORRECT_SQUARE);
	if (len_vector(square->normal_vector) > 1 ||
		len_vector(square->normal_vector) == 0)
		errorka(vars, INCORRECT_SQUARE);
	square->normal_vector = multiplying_vector(square->normal_vector,
									1.0 / len_vector(square->normal_vector));
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &square->side_size, INT_MIN + 1, INT_MAX))
		errorka(vars, INCORRECT_SQUARE);
	skip_space(vars, &str);
	if (!add_rgb(&str, &square->color))
		errorka(vars, INCORRECT_SQUARE);
	if (*str != '\0')
		errorka(vars, INCORRECT_SQUARE);
}
