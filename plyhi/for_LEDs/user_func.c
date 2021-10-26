/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:51:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/26 04:17:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LED.h"

color_t	EvenOdd(u16_t num)
{
	color_t	color;

	if (num % 2)
	{
		color.r = 0;
		color.g = 204;
		color.b = 252;
	}
	else
	{
		color.r = 255;
		color.g = 0;
		color.b = 102;
	}

	return color;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

color_t	RainbowPos(u16_t num)
{
	// 1530 period in rainbow;
	const u64_t	rainbow_pos = (double)1530 / STRIPLEN * num;
	u8_t		num_change_direction = rainbow_pos / 255;
	u8_t		spectrum = 1;
	int			move_dir = 1;
	u8_t		color[3];
	color_t		result;

	if (num_change_direction % 2)
		move_dir *= -1;
	spectrum = (spectrum + num_change_direction * 2) % 3;

	for (size_t i = 0; i < 3; ++i)
	{
		if (move_dir < 0)
		{
			if (i != (spectrum + 2) % 3)
				color[i] = 255;
			else
				color[i] = 0;
		}
		else
		{
			if (i != (spectrum + 2) % 3)
				color[i] = 0;
			else
				color[i] = 255;
		}
		if (i == spectrum)
			color[i] += rainbow_pos % 255 * move_dir;
	}
	result.r = color[0];
	result.g = color[1];
	result.b = color[2];
	return result;
}
