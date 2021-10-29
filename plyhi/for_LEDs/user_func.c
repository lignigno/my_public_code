/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:51:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/29 06:55:49 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LED.h"
#include "user_func.h"

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
	const u64_t	rainbow_pos = (double)RAINBOW_PERIOD / STRIPLEN * num;
	u8_t		num_change_direction = rainbow_pos / BRIGHTNESS;
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
				color[i] = BRIGHTNESS;
			else
				color[i] = 0;
		}
		else
		{
			if (i != (spectrum + 2) % 3)
				color[i] = 0;
			else
				color[i] = BRIGHTNESS;
		}
		if (i == spectrum)
			color[i] += rainbow_pos % BRIGHTNESS * move_dir;
	}
	result.r = color[0];
	result.g = color[1];
	result.b = color[2];
	return result;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

color_t	RainbowCall(u16_t not_use)
{
	(void)not_use;
	static u64_t	num_call = 0;
	// 1530 period in rainbow;
	const u64_t		rainbow_pos = (double)RAINBOW_PERIOD / TMP_STRIPLEN * num_call; 
	u8_t			num_change_direction = rainbow_pos / BRIGHTNESS;
	u8_t			spectrum = 1;
	int				move_dir = 1;
	u8_t			color[3];
	color_t			result;

	if (num_change_direction % 2)
		move_dir *= -1;
	spectrum = (spectrum + num_change_direction * 2) % 3;

	for (size_t i = 0; i < 3; ++i)
	{
		if (move_dir < 0)
		{
			if (i != (spectrum + 2) % 3)
				color[i] = BRIGHTNESS;
			else
				color[i] = 0;
		}
		else
		{
			if (i != (spectrum + 2) % 3)
				color[i] = 0;
			else
				color[i] = BRIGHTNESS;
		}
		if (i == spectrum)
			color[i] += rainbow_pos % BRIGHTNESS * move_dir;
	}
	result.r = color[0];
	result.g = color[1];
	result.b = color[2];
	++num_call;
	return result;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

color_t	GradientSlider(u16_t slider)
{
	color_t	start;
	color_t	end;
	double tmp[3];

	if (slider < STRIPLEN / 2 + 1)
	{
		start.r = 0;
		start.g = BRIGHTNESS;
		start.b = 0;
		end.r = BRIGHTNESS;
		end.g = BRIGHTNESS;
		end.b = 0;
	}
	else
	{
		start.r = BRIGHTNESS;
		start.g = BRIGHTNESS;
		start.b = 0;
		end.r = BRIGHTNESS;
		end.g = 0;
		end.b = 0;
	}
	
	tmp[0] = ((double)end.r - start.r) / (STRIPLEN / 2);
	tmp[1] = ((double)end.g - start.g) / (STRIPLEN / 2);
	tmp[2] = ((double)end.b - start.b) / (STRIPLEN / 2);

	tmp[0] *= slider % (STRIPLEN / 2 + 1);
	tmp[1] *= slider % (STRIPLEN / 2 + 1);
	tmp[2] *= slider % (STRIPLEN / 2 + 1);

	start.r += tmp[0];
	start.g += tmp[1];
	start.b += tmp[2];

	return start;
}
