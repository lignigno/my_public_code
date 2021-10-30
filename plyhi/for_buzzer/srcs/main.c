/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:47:22 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/30 09:23:38 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"
#include <unistd.h>
#include <sys/time.h>

// -----------------------------------------------------------------------------

#define getR(color) (((color) & 0xFF0000) >> 16)
#define getG(color) (((color) & 0x00FF00) >> 8)
#define getB(color) ((color) & 0x0000FF)

#define setR(color) (((color) & 0xFF) << 16)
#define setG(color) (((color) & 0xFF) << 8)
#define setB(color) ((color) & 0xFF)

#define BRIGHTNESS 255

int	get_a_color_gap(int start, int end, unsigned char slider)
{
	unsigned int	result;
	int				red;
	int				green;
	int				blue;

	red = getR(end) - getR(start);
	green = getG(end) - getG(start);
	blue = getB(end) - getB(start);
	result = start + (setR((int)((double)red / 255 * slider)) |
					setG((int)((double)green / 255 * slider)) |
					setB((int)((double)blue / 255 * slider)));
	return (result);
}

// -----------------------------------------------------------------------------

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(void)
{
	size_t height = 256;
	
	for (size_t i = 0; i < height; i += 8)
	{
		int color = get_a_color_gap(setR(BRIGHTNESS), setG(BRIGHTNESS), i);
		// printf("color %X %X res color %X", setR(BRIGHTNESS), setG(BRIGHTNESS), color);
		printf("\e[48;2;%i;%i;%im%*s\e[m\n", getR(color), getG(color), getB(color), 3, "");
	}
		// printf("\e[%zuA", height);
		// printf("\e[0J\n\e[2A\n");
		// usleep(1000000 / 60);
	return 0;
}
