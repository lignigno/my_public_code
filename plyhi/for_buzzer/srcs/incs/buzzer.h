/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:47:41 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/04 01:00:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUZZER_H
#define BUZZER_H

// _____________________________________________________________________INCLUDES

#include <stdio.h>

// ______________________________________________________________________DEFINES

#define C	16.3516015625
#define C_	17.32390625
#define D	18.35404296875
#define D_	19.4454296875
#define E	20.60171875
#define F	21.8267578125
#define F_	23.1246484375
#define G	24.49970703125
#define G_	25.95654296875
#define	A	27.5
#define	A_	29.135234375
#define B	30.86771484375

#define MC_Hz		32000000
#define AMPLITUDE	79; //TIMx->ARR
#define SIZE_FREQUENCY_ARR ((size_t)(MC_Hz / (B * (1 << 9))))

typedef u_int8_t	u8_t;	// unsigned 8-bit type
typedef u_int16_t	u16_t;	// unsigned 16-bit type
typedef u_int32_t	u32_t;	// unsigned 32-bit type
typedef u_int64_t	u64_t;	// unsigned 64-bit type

typedef u8_t	hz_t;
typedef u16_t	duration_t;

#define INIT_SOUND_SIZE(size) ((size) + sizeof(duration_t) + 1)
#define END_SOUND (hz_t)-1
#define NOT_NOTE (hz_t)-2
#define RESERVED NOT_NOTE

u8_t	FrequencyArr[SIZE_FREQUENCY_ARR];

void	InitSound(hz_t *sound, u64_t arr_size);
void	SetDuration(hz_t *sound, duration_t duration);
void	AddFrequency(hz_t *sound, double hz);
void	RemoveFrequency(hz_t *sound, u64_t position);
void	PlaySound(const hz_t *sound);

#endif