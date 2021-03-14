/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:46:03 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/26 03:26:12 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

/*
** FUNCTION NAME_:__________________________________________________________RGBA
** ________________________________________________________________MAIN FUNCTION
*/

int				rgba(int r, int g, int b, int a)
{
	r = r < 0 ? 0 : r;
	r = r > 255 ? 255 : r;
	g = g < 0 ? 0 : g;
	g = g > 255 ? 255 : g;
	b = b < 0 ? 0 : b;
	b = b > 255 ? 255 : b;
	a = a < 0 ? 0 : a;
	a = a > 255 ? 255 : a;
	return (a << 24 | r << 16 | g << 8 | b);
}

/*
** FUNCTION NAME_:_____________________________________________________PUT PIXEL
** ________________________________________________________________MAIN FUNCTION
*/

void			put_pixel(t_img_data data, int x, int y, int color)
{
	void	*pixel;

	pixel = data.addr + (data.width * y + x * (data.bit_per_pixel / 8));
	*(int*)pixel = color;
}

/*
** FUNCTION NAME_:______________________________________________________FILL IMG
** ________________________________________________________________MAIN FUNCTION
*/

void			fill_img(t_img_data dat, int color)
{
	int		x;
	int		y;
	void	*pixel;

	y = 0;
	while (y < dat.height)
	{
		x = 0;
		while (x < dat.width / (dat.bit_per_pixel / 8))
		{
			pixel = dat.addr + (dat.width * y + x * (dat.bit_per_pixel / 8));
			*(int*)pixel = color;
			x++;
		}
		y++;
	}
}

/*
** FUNCTION NAME_:________________________________________________________CLOSER
** ________________________________________________________________MAIN FUNCTION
*/

int				closer(t_vector p_1, t_vector p_2, t_vector p_start)
{
	double		len_1;
	double		len_2;

	if (p_2.x != p_2.x && p_1.x != p_1.x)
		return (0);
	if (p_2.x != p_2.x)
		return (1);
	p_1 = sum_vector(p_1, -1, p_start);
	p_2 = sum_vector(p_2, -1, p_start);
	len_1 = len_vector(p_1);
	len_2 = len_vector(p_2);
	return (len_1 < len_2 ? 1 : 0);
}
