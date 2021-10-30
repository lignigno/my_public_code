/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LEDs_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:30:03 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/29 06:50:10 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LED.h"

// ____________________________________________________________________FUNCTIONS

/*
 * Fills the bits of the lightBitTrain array with the necessary values to light the LED on the position
 *
 * 		@param lightBitTrain[] an array of bits for the LED strip. where 1 is LED_ON and 0 is LED_OFF.
 * 		@param position the position of the LED on the LED strip.
 * 		@param col_func function for calculating the color of the LED by its number.
*/
void	LightUpSingleLEDIter(data_bits_t lightBitTrain[], u16_t position, color_t (*colFunc)(u16_t))
{
	u32_t		bit;
	color_t		color;
	u32_t		spectrum;
	spectrum_t	col[3];

	color = colFunc(position);
	col[0] = color.g;
	col[1] = color.r;
	col[2] = color.b;
	spectrum = 0;
	while (spectrum < 3)
	{
		bit = 0;
		while (bit < 8)
		{
			lightBitTrain[position * 24 + spectrum * 8 + bit] = \
				col[spectrum] & (1 << (7 - bit)) ? LED_ON : LED_OFF;
			++bit;
		}
		++spectrum;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |


/*
 * Fills the bits of the lightBitTrain array with the necessary values to light the LED on the position
 *
 * 		@param lightBitTrain[] an array of bits for the LED strip. where 1 is LED_ON and 0 is LED_OFF.
 * 		@param position the position of the LED on the LED strip.
 * 		@param color what color should be installed on the LEDs in the range [from ; to).
*/
void	LightUpSingleLED(data_bits_t lightBitTrain[], u16_t position, const color_t *color)
{
	u32_t		bit;
	u32_t		spectrum;
	spectrum_t	col[3];

	col[0] = color->g;
	col[1] = color->r;
	col[2] = color->b;
	spectrum = 0;
	while (spectrum < 3)
	{
		bit = 0;
		while (bit < 8)
		{
			lightBitTrain[position * 24 + spectrum * 8 + bit] = \
				col[spectrum] & (1 << (7 - bit)) ? LED_ON : LED_OFF;
			++bit;
		}
		++spectrum;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

/*
 * Fills the lightBitTrain array with the necessary values to light the LEDs in the range [from ; to)
 * and set (to * 24) bit in 0
 *
 * 		@param lightBitTrain[] an array of bits for the LED strip. where 1 is LED_ON and 0 is LED_OFF.
 * 		@param from which LED to start with (including it). The first LED is 0.
 * 		@param to which LED to finish with (not including it).
 * 		@param col_func function for calculating the color of the LED by its number.
 * 		@return the number of bits to be transmitted + 1
*/
u64_t	LightUpLEDsRangeIter(data_bits_t lightBitTrain[], u16_t from, u16_t to, color_t (*colFunc)(u16_t))
{
	u32_t		i;
	u32_t		bit;
	color_t		color;
	u32_t		spectrum;
	spectrum_t	col[3];

	i = from;
	while (i < to)
	{
		color = colFunc(i);
		col[0] = color.g;
		col[1] = color.r;
		col[2] = color.b;
		spectrum = 0;
		while (spectrum < 3)
		{
			bit = 0;
			while (bit < 8)
			{
				lightBitTrain[i * 24 + spectrum * 8 + bit] = \
					col[spectrum] & (1 << (7 - bit)) ? LED_ON : LED_OFF;
				++bit;
			}
			++spectrum;
		}
		++i;
	}
	lightBitTrain[to * 24] = 0;
	return (to * 24 + 1);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

/*
 * Fills the lightBitTrain array with the necessary values to light the LEDs in the range [from ; to) 
 * and set (to * 24) bit in 0
 *
 * 		@param lightBitTrain[] an array of bits for the LED strip. where 1 is LED_ON and 0 is LED_OFF.
 * 		@param from which LED to start with (including it). The first LED is 0.
 * 		@param to which LED to finish with (not including it).
 * 		@param color what color should be installed on the LEDs in the range [from ; to).
 * 		@return the number of bits to be transmitted + 1
*/
u64_t	LightUpLEDsRange(data_bits_t lightBitTrain[], u16_t from, u16_t to, const color_t *color)
{
	u32_t		i;
	u32_t		bit;
	u32_t		spectrum;
	spectrum_t	col[8];

	col[0] = color->g;
	col[1] = color->r;
	col[2] = color->b;
	i = from;
	while (i < to)
	{
		spectrum = 0;
		while (spectrum < 3)
		{
			bit = 0;
			while (bit < 8)
			{
				lightBitTrain[i * 24 + spectrum * 8 + bit] = \
					col[spectrum] & (1 << (7 - bit)) ? LED_ON : LED_OFF;
				++bit;
			}
			++spectrum;
		}
		++i;
	}
	lightBitTrain[to * 24] = 0;
	return (to * 24 + 1);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	ShowLEDStrip(data_bits_t lightBitTrain[], u32_t num_data)
{
	u8_t		spectrum;
	spectrum_t	color[3];

	printf("--> |");
	spectrum = 2;
	for (size_t bit = 0; bit < num_data; ++bit)
	{
		if (!lightBitTrain[bit])
			continue ;
		spectrum += bit % 8 == 0;
		spectrum = spectrum < 3 ? spectrum : 0;

		color[spectrum] <<= 1;
		color[spectrum] |= lightBitTrain[bit] == LED_ON;

		if ((bit + 1) % 24 == 0)
			printf("\e[4;48;2;%i;%i;%i;38;2;%i;%i;%im \e[24m \e[m", color[1], color[0], color[2],
																	255 - color[1], 255 - color[0], 255 - color[2]);
	}
	printf("| -->\n");
}
