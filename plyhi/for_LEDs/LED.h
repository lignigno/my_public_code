/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LED.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:44:11 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/26 23:30:48 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LED_H
#define LED_H

// _____________________________________________________________________INCLUDES

#include <stdio.h>

// ______________________________________________________________________DEFINES

#define LED_ON 1
#define LED_OFF 0

#define STRIPLEN 21
#define STRIPLEN_BIT (STRIPLEN * 24)

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

void	LightUpLEDsIter(data_bits_t lightBitTrain[], u16_t from, u16_t to, color_t (*colFunc)(u16_t));
void	LightUpLEDs(data_bits_t lightBitTrain[], u16_t from, u16_t to, const color_t *color);
void	ShowLEDStrip(data_bits_t lightBitTrain[], u32_t numLEDs);

#endif //LED_H
