/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LED.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:44:11 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/29 06:58:49 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LED_H
#define LED_H

// _____________________________________________________________________INCLUDES

#include <stdio.h> // for ShowLEDStrip

// ______________________________________________________________________DEFINES

// replace with your T0H value for the PWM signal width.
// LED_OFF must not be equal to 0
#define LED_OFF 10

// replace with your T1H value for the PWM signal width
// LED_ON must be more LED_OFF
#define LED_ON 20

// BRIGHTNESS [0 ; 255]
#define BRIGHTNESS 255
#define RAINBOW_PERIOD (BRIGHTNESS * 6)

#define STRIPLEN 21
// + 1 to get rid of garbage when calling HAL_TIM_PWM_Start_DMA
#define STRIPLEN_BIT (STRIPLEN * 24 + 1)

// ___________________________________________________________TYPEDEFS / STRUCTS

// set   user type
//        ||
//        \/
typedef u_int8_t	u8_t;	// unsigned 8-bit type
typedef u_int16_t	u16_t;	// unsigned 16-bit type
typedef u_int32_t	u32_t;	// unsigned 32-bit type
typedef u_int64_t	u64_t;	// unsigned 64-bit type

typedef	u8_t	spectrum_t;
typedef u16_t	data_bits_t;

typedef struct color_s
{
	spectrum_t	r;
	spectrum_t	g;
	spectrum_t	b;
}				color_t;

// ___________________________________________________________________PROTOTYPES

void	LightUpSingleLEDIter(data_bits_t lightBitTrain[], u16_t position, color_t (*colFunc)(u16_t));
void	LightUpSingleLED(data_bits_t lightBitTrain[], u16_t position, const color_t *color);
u64_t	LightUpLEDsRangeIter(data_bits_t lightBitTrain[], u16_t from, u16_t to, color_t (*colFunc)(u16_t));
u64_t	LightUpLEDsRange(data_bits_t lightBitTrain[], u16_t from, u16_t to, const color_t *color);
void	ShowLEDStrip(data_bits_t lightBitTrain[], u32_t num_data);

#endif //LED_H
