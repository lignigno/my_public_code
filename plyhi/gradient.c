/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 07:59:12 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/05 21:44:34 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define COLOR_1 0x3498db
#define COLOR_2 0xe67e22

unsigned int		get_a_color_gap(int start, int end, unsigned char slider)
{
	unsigned int	result;
	int				red;
	int				green;
	int				blue;

	red = ((end & 0xff0000) >> 16) - ((start & 0xff0000) >> 16);
	green = ((end & 0xff00) >> 8) - ((start & 0xff00) >> 8);
	blue = (end & 0xff) - (start & 0xff);
	result = start + (((int)((double)red / 256 * slider) & 0xff) << 16 |
					((int)((double)green / 256 * slider) & 0xff) << 8 |
					((int)((double)blue / 256 * slider) & 0xff));
	return (result);
}

int					main(void)
{
	int				color;

	for (int i = 0; i < 256; i++)
	{
		color = get_a_color_gap(COLOR_1, COLOR_2, i);
		printf("slider : [%3i] color \e[48;2;%i;%i;%im              \e[0m\n", i, (color & 0xff0000) >> 16,
																				 (color & 0xff00) >> 8,
																				  color & 0xff);
	}
	return (0);
}