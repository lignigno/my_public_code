/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 07:59:12 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/05 22:51:47 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define	NewColor(r, g, b) (((0xFF & (r)) << 16) | ((0xFF & (g)) << 8) | (0xFF & (b)))
#define	GetR(color) (((color) & 0xFF0000) >> 16)
#define	GetG(color) (((color) & 0x00FF00) >> 8)
#define	GetB(color) ((color) & 0x0000FF)
#define	SetR(color, r) ((color) | ((0xFF & (r)) << 16))
#define	SetG(color, g) ((color) | ((0xFF & (g)) << 8))
#define	SetB(color, b) ((color) | (0xFF & (b)))

#define COL_START 0x1515bf
#define COL_END 0xeb0052

unsigned int		get_a_color_gap(int start, int end, unsigned char slider)
{
	unsigned int	result;
	int				red;
	int				green;
	int				blue;

	red		= GetR(end) - GetR(start);
	green	= GetG(end) - GetG(start);
	blue	= GetB(end) - GetB(start);
	result = start + NewColor((int)((double)red / 256 * slider),
								(int)((double)green / 256 * slider),
								(int)((double)blue / 256 * slider));
	return (result);
}

int					main(void)
{
	int				color;

	for (int i = 0; i < 256; i++)
	{
		color = get_a_color_gap(COL_START, COL_END, i);

		printf("slider : [%3i] \e[48;2;", i);
		printf("%i;", (color & 0xff0000) >> 16);
		printf("%i;", (color & 0xff00) >> 8);
		printf("%im", color & 0xff);
		printf("%*s\e[m\n", 21, "");
	}
	return (0);
}