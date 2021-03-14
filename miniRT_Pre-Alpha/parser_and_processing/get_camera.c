/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:16:48 by lignigno          #+#    #+#             */
/*   Updated: 2021/03/13 01:24:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** __________________________________________________________________SUBFUNCTION
*/

static void		skip_space(t_vars *vars, char **str)
{
	if (**str != ' ')
		errorka(vars, INCORRECT_CAMERA);
	while (**str == ' ')
		(*str)++;
}

/*
** //printf("cam_create : %p\n", new_cam);
*/

static t_cam	*create_cam(t_vars *vars)
{
	t_cam		*new_cam;
	t_cam		*iterator;

	new_cam = malloc(sizeof(t_cam));
	if (new_cam == NULL)
		errorka(vars, NMA_CAMERA);
	if (vars->objects.cam == NULL)
	{
		vars->objects.cam = new_cam;
		vars->objects.cam->next = NULL;
	}
	else
	{
		iterator = vars->objects.cam;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_cam;
		iterator->next->next = NULL;
	}
	vars->need_cleared[CAM] = 1;
	vars->cleared_func[CAM] = free_cam;
	return (new_cam);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			get_camera(t_vars *vars, char *str)
{
	t_cam		*cam;

	cam = create_cam(vars);
	str++;
	skip_space(vars, &str);
	if (!get_coordinates(&str, &cam->coordinates))
		errorka(vars, INCORRECT_CAMERA);
	skip_space(vars, &str);
	if (!get_coordinates(&str, &cam->orientation))
		errorka(vars, INCORRECT_CAMERA);
	if (1 < cam->orientation.x || cam->orientation.x < -1 ||
		1 < cam->orientation.y || cam->orientation.y < -1 ||
		1 < cam->orientation.z || cam->orientation.z < -1 ||
		len_vector(cam->orientation) > 1 ||
		len_vector(cam->orientation) == 0)
		errorka(vars, INCORRECT_CAMERA);
	skip_space(vars, &str);
	if (!get_int_num_in_range(&str, (long*)(&cam->fov), 0, FOV_MAX))
		errorka(vars, INCORRECT_CAMERA);
	if (*str != '\0')
		errorka(vars, INCORRECT_CAMERA);
	vars->current_cam = vars->objects.cam;
}
