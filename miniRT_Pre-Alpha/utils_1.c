/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:46:03 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/12 11:49:38 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

int				rgba(int r, int g, int b, int a)
{
	if ((0 > r && r > 255) || 
		(0 > g && g > 255) ||
		(0 > b && b > 255) ||
		(0 > a && a > 255))
		return (0);
	return (a << 24 | r << 16 | g << 8 | b);
}

void			put_pixel(t_img_data data, int x, int y, int color)
{
	void	*pixel;

	pixel = data.addr + (data.width * y + x * (data.bit_per_pixel / 8));
		*(int*)pixel = color;
}

void			fill_img(t_img_data dat, int color)
{
	int		x;
	int		y;
	void	*pixel;

	y = 0;
	while (y < dat.height)
	{
		x = 0;
		while (x < dat.width / 4)
		{
			pixel = dat.addr + (dat.width * y + x * (dat.bit_per_pixel / 8));
			*(int*)pixel = color;
			x++;
		}
		y++;
	}
}
