/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:16:48 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 02:02:14 by lignigno         ###   ########.fr       */
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
		while (vars->objects.cam->next != NULL)
			vars->objects.cam = vars->objects.cam->next;
		vars->objects.cam->next = new_cam;
		vars->objects.cam->next->next = NULL;
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
	if (!get_coordinates(&str, cam->coordinates))
		errorka(vars, INCORRECT_CAMERA);
	skip_space(vars, &str);
	if (!get_coordinates(&str, cam->normal_vector))
		errorka(vars, INCORRECT_CAMERA);
	if (1 < cam->normal_vector[0] || cam->normal_vector[0] < -1 ||
		1 < cam->normal_vector[1] || cam->normal_vector[1] < -1 ||
		1 < cam->normal_vector[2] || cam->normal_vector[2] < -1)
		errorka(vars, INCORRECT_CAMERA);
	skip_space(vars, &str);
	if (!get_int_num_in_range(&str, (long*)(&cam->fov), 0, 180))
		errorka(vars, INCORRECT_CAMERA);
	if (*str != '\0')
		errorka(vars, INCORRECT_CAMERA);
}

/*
**int main(int argc, char const *argv[])
**{
**	t_vars	vars;
**	t_cam	*cam;
**	char	*str1 = ft_strdup("c -32323.2423,1.234,42 -0.4,-1,1.0000000 0");
**	char	*str2 = ft_strdup("c -2,1.42,42 -1,0.421,1.0000000 180");
**
**	vars.objects.cam = NULL;
**	printf("point_str_1 : |%p|\n\n", vars.objects.cam);
**	get_camera(&vars, str1);
**	printf("point_str_1 : |%p|\n\n", vars.objects.cam);
**	cam = vars.objects.cam;
**	if (vars.objects.cam != NULL)
**	{
**		printf("point_str_1 : x = |%g|\n", cam->coordinates[0]);
**		printf("point_str_1 : y = |%g|\n", cam->coordinates[1]);
**		printf("point_str_1 : z = |%g|\n\n", cam->coordinates[2]);
**		printf("point_str_1 : n_x = |%g|\n", cam->normal_vector[0]);
**		printf("point_str_1 : n_y = |%g|\n", cam->normal_vector[1]);
**		printf("point_str_1 : n_z = |%g|\n", cam->normal_vector[2]);
**		printf("point_str_1 : fov = |%i|\n\n", cam->fov);
**	}
**	printf("-------------------------\n");
**	printf("point_str_2 : |%p|\n\n", vars.objects.cam->next);
**	get_camera(&vars, str2);
**	printf("point_str_2 : |%p|\n\n", vars.objects.cam->next);
**	cam = vars.objects.cam->next;
**	if (vars.objects.cam != NULL)
**	{
**		printf("point_str_2 : x = |%g|\n", cam->coordinates[0]);
**		printf("point_str_2 : y = |%g|\n", cam->coordinates[1]);
**		printf("point_str_2 : z = |%g|\n\n", cam->coordinates[2]);
**		printf("point_str_2 : n_x = |%g|\n", cam->normal_vector[0]);
**		printf("point_str_2 : n_y = |%g|\n", cam->normal_vector[1]);
**		printf("point_str_2 : n_z = |%g|\n\n", cam->normal_vector[2]);
**		printf("point_str_2 : fov = |%i|\n\n", cam->fov);
**	}
**	cleaner(&vars);
**	free(str1);
**	free(str2);
**	return 0;
**}
** //gcc cleaner/cleaner.c cleaner/free_cam.c errorka.c
** //parser_and_processing/get_camera.c
** //parser_and_processing/utils_for_parser_1.c
** //parser_and_processing/utils_for_parser_2.c
** //libft/ft_strlen.c libft/ft_strdup.c
*/
