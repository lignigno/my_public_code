/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:45:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/26 00:08:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LED.h"
#include "user_func.h"

#define STRIPLEN 100
#define STRIPLEN_BIT (STRIPLEN * 24)

// ____________________________________________________________________MAIN FUNC

int main(void)
{
	
	data_bits_t	lightBitTrain[STRIPLEN_BIT];
	color_t		color;

	for (size_t i = 0; i < STRIPLEN_BIT; ++i)
		lightBitTrain[i] = 0;

	// синим
	color.r = 0;
	color.g = 204;
	color.b = 252;
	LightUpLEDs(lightBitTrain, 2, 6, &color);
	ShowLEDStrip(lightBitTrain, STRIPLEN);

	printf("\n");

	// чередование
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
