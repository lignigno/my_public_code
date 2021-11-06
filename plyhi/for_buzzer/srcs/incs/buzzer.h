/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:05:26 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/06 07:53:37 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

// _____________________________________________________________________INCLUDES

#include "main.h"
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

#define MC_Hz			32000000
#define PERIOD_SIG		50
#define MAX_FREQUENCY	16000
#define TIMx_ARR_VAL	(MC_Hz / MAX_FREQUENCY / PERIOD_SIG - 1)

#define	TIMx_ARR		TIM1->ARR
#define TIMx_PSC		TIM1->PSC

typedef uint8_t		u8_t;	// unsigned 8-bit type
typedef uint16_t	u16_t;	// unsigned 16-bit type
typedef uint32_t	u32_t;	// unsigned 32-bit type
typedef uint64_t	u64_t;	// unsigned 64-bit type

// no more TIMx_ARR_VAL
typedef u8_t		signal_t;
typedef u8_t		vol_t;

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
void	PlaySound(u16_t hz, u32_t duration, u8_t mode);


#endif /* INC_BUZZER_H_ */
