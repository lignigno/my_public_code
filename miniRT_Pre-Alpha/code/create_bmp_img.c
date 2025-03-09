/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:42:37 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/28 22:45:19 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

static char		*invert_img(t_vars *vars, t_img_data img)
{
	ssize_t		x;
	ssize_t		y;
	ssize_t		size;
	char		*result;

	size = img.width * img.height * sizeof(char);
	result = malloc(size);
	if (result == NULL)
		errorka(vars, NMA_INVERT);
	y = 0;
	size--;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width / (img.bit_per_pixel / 8))
		{
			*(int*)(result +
			(img.width * y + x * (img.bit_per_pixel / 8))) = *(int*)(img.addr +
			(img.height - y) * img.width + x * img.bit_per_pixel / 8);
			x++;
		}
		y++;
	}
	return (result);
}

static void		write_picture_in_file_part_1(t_vars *vars, t_cam *cam, int file)
{
	short		short_tmp;
	unsigned	unsign_tmp;

	if (cam == NULL)
		return ;
	write(file, "BM", 2);
	unsign_tmp = 54 + cam->view.bit_per_pixel / 8 *
					cam->view.width * cam->view.height;
	write(file, &unsign_tmp, 4);
	unsign_tmp = 0;
	write(file, &unsign_tmp, 4);
	unsign_tmp = 54;
	write(file, &unsign_tmp, 4);
	unsign_tmp = 40;
	write(file, &unsign_tmp, 4);
	write(file, &vars->w_win, 4);
	write(file, &vars->h_win, 4);
	short_tmp = 1;
	write(file, &short_tmp, 2);
}

static void		write_picture_in_file_part_2(t_vars *vars, t_cam *cam, int file)
{
	unsigned	tmp;
	char		*img;

	write(file, &cam->view.bit_per_pixel, 2);
	tmp = 0;
	write(file, &tmp, 4);
	write(file, &tmp, 4);
	tmp = vars->w_win;
	write(file, &tmp, 4);
	tmp = vars->h_win;
	write(file, &tmp, 4);
	tmp = 0;
	write(file, &tmp, 4);
	write(file, &tmp, 4);
	img = invert_img(vars, cam->view);
	write(file, img, cam->view.width * cam->view.height);
	free(img);
}

static int		open_or_create(t_vars *vars, int number, char *file_name)
{
	int			file;
	char		*str_num;
	char		*full_file_name;

	str_num = ft_itoa(number);
	if (str_num == NULL)
		errorka(vars, NMA_SAVE);
	full_file_name = ft_strjoin(str_num, file_name);
	if (full_file_name == NULL)
	{
		free(str_num);
		errorka(vars, NMA_SAVE);
	}
	file = open(full_file_name, O_RDWR | O_CREAT, 0755);
	free(str_num);
	free(full_file_name);
	if (file < 0)
		errorka(vars, NMA_SAVE);
	return (file);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			create_bmp_img(t_vars *vars)
{
	int			file;
	int			count;
	t_cam		*iterator;

	count = 1;
	iterator = vars->objects.cam;
	while (iterator != NULL)
	{
		file = open_or_create(vars, count, "_Camera.bmp");
		write_picture_in_file_part_1(vars, iterator, file);
		write_picture_in_file_part_2(vars, iterator, file);
		close(file);
		iterator = iterator->next;
		count++;
	}
}
