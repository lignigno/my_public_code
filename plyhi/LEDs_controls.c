/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LEDs_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:30:03 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/24 09:24:06 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// _____________________________________________________________________INCLUDES

#include <stdio.h>

// ______________________________________________________________________DEFINES

#define LED_ON 1
#define LED_OFF 0

// ___________________________________________________________TYPEDEFS / STRUCTS

// set   user type
//        ||
//        \/
typedef u_int8_t	u8_t;	// unsigned 8-bit type
typedef u_int16_t	u16_t;	// unsigned 16-bit type
typedef u_int32_t	u32_t;	// unsigned 32-bit type

typedef	u8_t	spectrum_t;
typedef u16_t	data_bits_t;

typedef struct color_s
{
	spectrum_t	r;
	spectrum_t	g;
	spectrum_t	b;
}				color_t;

// ___________________________________________________________________PROTOTYPES

void	LightUpLEDsIter(data_bits_t lightBitTrain[], u16_t from, u16_t to, color_t (*colFunc)(u32_t));
void	LightUpLEDs(data_bits_t lightBitTrain[], u16_t from, u16_t to, const color_t *color);

// _______________________________________________________________USER ITER FUNC

color_t	EvenOdd(u32_t num)
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

// ____________________________________________________________________FUNCTIONS

/*
 * Fills the lightBitTrain array with the necessary values to light the LEDs in the range [from ; to)
 *
 * 		@param lightBitTrain[] an array of bits for the LED strip. where 1 is LED_ON and 0 is LED_OFF.
 * 		@param from which LED to start with (including it). The first LED is 0.
 * 		@param to which LED to finish with (not including it).
 * 		@param col_func function for calculating the color of the LED by its number.
*/
void	LightUpLEDsIter(data_bits_t lightBitTrain[], u16_t from, u16_t to, color_t (*colFunc)(u32_t))
{
	u32_t		i;
	u32_t		bit;
	u32_t		spectrum;
	color_t		color;
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
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

/*
 * Fills the lightBitTrain array with the necessary values to light the LEDs in the range [from ; to)
 *
 * 		@param lightBitTrain[] an array of bits for the LED strip. where 1 is LED_ON and 0 is LED_OFF.
 * 		@param from which LED to start with (including it). The first LED is 0.
 * 		@param to which LED to finish with (not including it).
 * 		@param color what color should be installed on the LEDs in the range [from ; to).
*/
void	LightUpLEDs(data_bits_t lightBitTrain[], u16_t from, u16_t to, const color_t *color)
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
}

// ____________________________________________________________________MAIN FUNC

#define STRIPLEN 10
#define STRIPLEN_BIT (STRIPLEN * 24)

void	ShowLEDStrip(data_bits_t lightBitTrain[], u32_t numLEDs)
{
	u8_t		spectrum;
	spectrum_t	color[3];

	printf(" ||\n \\/\n");
	spectrum = 2;
	for (size_t bit = 0; bit < numLEDs * 24; ++bit)
	{
		spectrum += bit % 8 == 0;
		spectrum = spectrum < 3 ? spectrum : 0;

		color[spectrum] <<= 1;
		color[spectrum] |= lightBitTrain[bit] == LED_ON;

		if ((bit + 1) % 24 == 0)
			printf("[\e[4;48;2;%i;%i;%im  \e[m]\n", color[1], color[0], color[2]);
	}
	printf(" ||\n \\/\n");
}

int main(int argc, char const *argv[])
{
	data_bits_t	lightBitTrain[STRIPLEN_BIT];
	color_t		color;

	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	color.r = 0;
	color.g = 204;
	color.b = 252;
	LightUpLEDs(lightBitTrain, 0, 3, &color);
	ShowLEDStrip(lightBitTrain, STRIPLEN);

	printf("\n");

	LightUpLEDsIter(lightBitTrain, 0, STRIPLEN, EvenOdd);
	ShowLEDStrip(lightBitTrain, STRIPLEN);

	printf("\n");

	color.r = 255;
	color.g = 0;
	color.b = 102;
	LightUpLEDs(lightBitTrain, 0, STRIPLEN, &color);
	ShowLEDStrip(lightBitTrain, STRIPLEN);

	
	return 0;
}
