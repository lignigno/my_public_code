/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:09:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:33:43 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		parsing_received_string(t_vars *vars, char *str, int *ra_letter)
{
	if (str[0] == 'R' && ra_letter[0] == 'R')
		errorka(vars, R_WAS_SET);
	if (str[0] == 'A' && ra_letter[1] == 'A')
		errorka(vars, A_WAS_SET);
	if (str[0] == 'R')
		get_resolution(vars, str);
	else if (str[0] == 'A')
		get_ambient(vars, str);
	else if (str[0] == 'c' && str[1] != 'y')
		get_camera(vars, str);
	else if (str[0] == 'l')
		get_light(vars, str);
	else if (str[0] == 'p' && str[1] == 'l')
		get_plane(vars, str);
	else if (str[0] == 's' && str[1] == 'p')
		get_sphere(vars, str);
	else if (str[0] == 's' && str[1] == 'q')
		get_square(vars, str);
	else if (str[0] == 'c' && str[1] == 'y')
		get_cylinder(vars, str + 2);
	else if (str[0] == 't' && str[1] == 'r')
		get_triangle(vars, str);
	else if (str[0] != '\0')
		errorka(vars, NOT_EMPTY_NOT_NEW_LINE);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			parser_scene_file(t_vars *vars, char *file_name)
{
	int			ra_letter[2];
	int			result_gnl;
	char		*str;
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		errorka(vars, CANT_OPEN);
	result_gnl = 1;
	while (result_gnl)
	{
		result_gnl = gnl(fd, &str);
		if (result_gnl < 0)
			errorka(vars, READ_DIED);
		parsing_received_string(vars, str, ra_letter);
		ra_letter[0] = str[0] == 'R' ? 'R' : 0;
		ra_letter[1] = str[0] == 'A' ? 'A' : 0;
		free(str);
	}
	if (vars->objects.cam == NULL)
		errorka(vars, INCORRECT_CAMERA);
}
