/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:38:06 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/26 15:36:49 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void			skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_TRIANGLE);
	while (**str == ' ')
		(*str)++;
}

/*
** //printf("cam_create : %p\n", new_cam);
*/

static t_triangle	*create_triangle(t_vars *vars)
{
	t_triangle		*new_triangle;
	t_triangle		*iterator;

	new_triangle = malloc(sizeof(t_triangle));
	if (new_triangle == NULL)
		errorka(vars, NMA_TRIANGLE);
	if (vars->objects.triangle == NULL)
	{
		vars->objects.triangle = new_triangle;
		vars->objects.triangle->next = NULL;
	}
	else
	{
		iterator = vars->objects.triangle;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_triangle;
		iterator->next->next = NULL;
	}
	new_triangle->color = 0;
	vars->need_cleared[TRIANGLE] = 1;
	vars->cleared_func[TRIANGLE] = free_triangle;
	return (new_triangle);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void				get_triangle(t_vars *vars, char *str)
{
	t_triangle		*triangle;

	triangle = create_triangle(vars);
	str += 2;
	skip_space(vars, &str);
	if (!get_coordinates(&str, &triangle->a))
		errorka(vars, INCORRECT_TRIANGLE);
	skip_space(vars, &str);
	if (!get_coordinates(&str, &triangle->b))
		errorka(vars, INCORRECT_TRIANGLE);
	skip_space(vars, &str);
	if (!get_coordinates(&str, &triangle->c))
		errorka(vars, INCORRECT_TRIANGLE);
	skip_space(vars, &str);
	if (!add_rgb(&str, &triangle->color))
		errorka(vars, INCORRECT_TRIANGLE);
	if (*str != '\0')
		errorka(vars, INCORRECT_TRIANGLE);
}
