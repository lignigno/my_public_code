/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:45:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/26 23:38:13 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LED.h"
#include "user_func.h"

#define new_line printf("\n");

// ____________________________________________________________________MAIN FUNC

int main(void)
{
	
	data_bits_t	lightBitTrain[STRIPLEN_BIT];
	color_t		color;
	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	// blue
	color.r = 0;
	color.g = 204;
	color.b = 252;
	LightUpLEDs(lightBitTrain, 2, 6, &color);
	ShowLEDStrip(lightBitTrain, STRIPLEN);
	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	new_line

	// with some user_func
	LightUpLEDsIter(lightBitTrain, 0, STRIPLEN, RainbowPos);
	ShowLEDStrip(lightBitTrain, STRIPLEN);
	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	new_line

	// with some user_func
	LightUpLEDsIter(lightBitTrain, 3, STRIPLEN - 5, RainbowPos);
	ShowLEDStrip(lightBitTrain, STRIPLEN);
	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	new_line

	// with some user_func
	LightUpLEDsIter(lightBitTrain + (10 * 24), 0, STRIPLEN - 10, RainbowPos);
	ShowLEDStrip(lightBitTrain, STRIPLEN);
	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	new_line

	// not blue :)
	color.r = 255;
	color.g = 0;
	color.b = 102;
	LightUpLEDs(lightBitTrain, 0, STRIPLEN, &color);
	ShowLEDStrip(lightBitTrain, STRIPLEN);

	new_line

	{
		// for this example, I put STRIPLEN = 10 in RainbowCall
		data_bits_t	tmp_lightBitTrain[TMP_STRIPLEN_BIT];
		u8_t		arrPos[TMP_STRIPLEN] = {7, 3, 1, 5, 0, 9, 8, 2, 6, 4};
	
		for (size_t i = 0; i < TMP_STRIPLEN; ++i)
			tmp_lightBitTrain[i] = 0;

		for (size_t i = 0; i < 10; i++)
		{
			// with some user_func
			LightUpLEDsIter(tmp_lightBitTrain, arrPos[i], arrPos[i] + 1, RainbowCall);
			ShowLEDStrip(tmp_lightBitTrain, TMP_STRIPLEN);
			new_line
		}
	}

	return 0;
}
