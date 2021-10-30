/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:45:08 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/30 13:07:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LED.h"
#include "user_func.h"

#define new_line printf("\n");

// _________________________________________________________________SUBFUNCTIONS

void	ResetLEDs(data_bits_t arrayOfBits[], u64_t numBits, data_bits_t resetValue)
{
	for (size_t i = 0; i < numBits; ++i)
		arrayOfBits[i] = resetValue;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_blue(data_bits_t lightBitTrain[])
{
	u64_t	num_data;
	color_t	color;

	color.r = 0;
	color.g = 204;
	color.b = 252;
	num_data = LightUpLEDsRange(lightBitTrain, 2, 6, &color);
	ShowLEDStrip(lightBitTrain, num_data);
	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_not_blue(data_bits_t lightBitTrain[])
{
	u64_t	num_data;
	color_t	color;

	color.r = 255;
	color.g = 0;
	color.b = 102;
	num_data = LightUpLEDsRange(lightBitTrain, 0, STRIPLEN, &color);
	ShowLEDStrip(lightBitTrain, num_data);
	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_user_func_RainbowPos_full(data_bits_t lightBitTrain[])
{
	u64_t	num_data;

	num_data = LightUpLEDsRangeIter(lightBitTrain, 0, STRIPLEN, RainbowPos);
	ShowLEDStrip(lightBitTrain, num_data);
	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_user_func_RainbowPos_from_to(data_bits_t lightBitTrain[])
{
	u64_t	num_data;

	num_data = LightUpLEDsRangeIter(lightBitTrain, 3, STRIPLEN - 5, RainbowPos);
	ShowLEDStrip(lightBitTrain, num_data);
	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_user_func_RainbowPos_offset(data_bits_t lightBitTrain[])
{
	u32_t	offset = 10;

	LightUpLEDsRangeIter(lightBitTrain + (offset * 24), 0, STRIPLEN - offset, RainbowPos);
	ShowLEDStrip(lightBitTrain, STRIPLEN_BIT);
	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_user_func_GradientSlider(data_bits_t lightBitTrain[])
{
	u64_t	num_data;

	num_data = LightUpLEDsRangeIter(lightBitTrain, 0, STRIPLEN, GradientSlider);
	ShowLEDStrip(lightBitTrain, num_data);
	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	example_user_func_RainbowCall(void)
{
	// for this example, I put STRIPLEN = 10 in RainbowCall
	data_bits_t	tmp_lightBitTrain[TMP_STRIPLEN_BIT];
	u8_t		arrPos[TMP_STRIPLEN] = {9, 0, 6, 7, 4, 2, 3, 1, 8, 5};

	for (size_t i = 0; i < TMP_STRIPLEN_BIT; ++i)
		tmp_lightBitTrain[i] = LED_OFF; 
	tmp_lightBitTrain[TMP_STRIPLEN_BIT - 1] = 0;

	for (size_t i = 0; i < TMP_STRIPLEN; ++i)
	{
		// with some user_func
		LightUpSingleLEDIter(tmp_lightBitTrain, arrPos[i], RainbowCall);
		ShowLEDStrip(tmp_lightBitTrain, TMP_STRIPLEN_BIT);
		new_line
	}
}

// ____________________________________________________________________MAIN FUNC

#include <unistd.h>

int main(void)
{
	data_bits_t	lightBitTrain[STRIPLEN_BIT];

	ResetLEDs(lightBitTrain, STRIPLEN_BIT, LED_OFF);
	new_line

	example_blue(lightBitTrain);
	new_line

	example_not_blue(lightBitTrain);
	new_line

	example_user_func_RainbowPos_full(lightBitTrain);
	new_line

	example_user_func_RainbowPos_from_to(lightBitTrain);
	new_line

	example_user_func_RainbowPos_offset(lightBitTrain);
	new_line

	example_user_func_GradientSlider(lightBitTrain);
	new_line

	example_user_func_RainbowCall();

	return 0;
}
