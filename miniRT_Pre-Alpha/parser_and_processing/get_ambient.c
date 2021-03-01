/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:58:13 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/30 03:24:50 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_AMBIENT);
	while (**str == ' ')
		(*str)++;
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_ambient(t_vars *vars, char *str)
{
	double		alpha;

	str++;
	skip_space(vars, &str);
	if (!get_dbl_num_in_range(&str, &alpha, 0, 1))
		errorka(vars, INCORRECT_AMBIENT);
	vars->ambient = IN_A_HUMAN_WAY ? (1 - alpha) * 255 : alpha * 255;
	skip_space(vars, &str);
	if (!add_rgb(&str, &vars->ambient))
		errorka(vars, INCORRECT_AMBIENT);
	if (*str != '\0')
		errorka(vars, INCORRECT_AMBIENT);
}

/*
**int				main(int argc, char const *argv[])
**{
**	if (argc == 1)
**	{
**		printf("\033[31;1mТы долбаёб\n");
**		return (0);
**	}
**	t_vars		vars;
**
**	vars.ambient = 0;
**	get_ambient(&vars, (char*)argv[1]);
**	printf("alpha : %i\nred : %i\ngreen : %i\nblue : %i\n",
**	(vars.ambient & 0xff000000) >> 24,
**	(vars.ambient & 0x00ff0000) >> 16,
**	(vars.ambient & 0x0000ff00) >> 8,
**	 vars.ambient & 0x000000ff);
**	return 0;
**}
*/
