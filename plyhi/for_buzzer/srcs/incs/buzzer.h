/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:05:26 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/07 16:52:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

// _____________________________________________________________________INCLUDES

#include // "main.h"
#include <math.h>

// ______________________________________________________________________DEFINES


// BASE OCTAVE

/*
 * any other octave can be obtained by the formula
 * note * 2 in degree (octave number)
 * octave number [0 ; 9]
 * 
 * example :
 *     G_ * (1 << 0)
 *     F * (1 << 3)
*/
#define C	16.3516015625	// 0
#define C_	17.32390625		// 1
#define D	18.35404296875	// 2
#define D_	19.4454296875	// 3
#define E	20.60171875		// 4
#define F	21.8267578125	// 5
#define F_	23.1246484375	// 6
#define G	24.49970703125	// 7
#define G_	25.95654296875	// 8
#define	A	27.5			// 9
#define	A_	29.135234375	// 10
#define B	30.86771484375	// 11

// INIT VOLUMES
#define INIT_VOL_SIN	// 10
#define INIT_VOL_SQR	// 10
#define INIT_VOL_PWM	// 1

#define TIM_FRQ			// 32000000
#define PERIOD_SIG		// 50
#define MAX_FREQUENCY	// 16000
#define TIMx_ARR_VAL	((double)TIM_FRQ / MAX_FREQUENCY / PERIOD_SIG - 1)

#define	TIMx_ARR		// TIM1->ARR
#define TIMx_PSC		// TIM1->PSC
#define TIMx_CCR		// TIM1->CCR1

typedef // uint8_t		u8_t;	// unsigned 8-bit type
typedef // uint16_t	u16_t;	// unsigned 16-bit type
typedef // uint32_t	u32_t;	// unsigned 32-bit type
typedef // uint64_t	u64_t;	// unsigned 64-bit type

// note   [0 ; 11]
// octave [0 ; 9]
#define SET_OCTAVE(octave) ((((u8_t)octave) % 12) & 0xF)
#define SET_NOTE(octave) ((((u8_t)octave) % 10) & 0xF)
#define FRQ(octave, note) ((SET_OCTAVE(octave) << 4) | SET_NOTE(note))

typedef u16_t		signal_t; // no more TIMx_ARR_VAL
typedef u8_t		vol_t; // no more TIMx_ARR_VAL
typedef u32_t		dur_t;

enum sound_mode_e
{
	MODE_SIN,
	MODE_SQR,
	MODE_PWM,
	NOT_VALID,
};

signal_t	SinSig[PERIOD_SIG];
signal_t	SqrSig[PERIOD_SIG];
signal_t	PwmSig[1];

void	SetCIRCModeDMA(void);
void	PWM_Start(u32_t *pData, u16_t Length);
void	PWM_Stop(void);
void	Duration(u32_t duration);

void	InitSound(void);
void	ChangeVolume(u8_t mode, vol_t volume);
void	PlaySoundRawFrq(u16_t frq, dur_t duration_ms, u8_t mode);
void	PlaySound(u8_t frq, u32_t duration, u8_t mode);


#endif /* INC_BUZZER_H_ */
