/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:53:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/07 16:49:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"

// _____________________________________________________________________________

void	InitSound(void)
{
	ChangeVolume(MODE_SIN, INIT_VOL_SIN);
	ChangeVolume(MODE_SQR, INIT_VOL_SQR);
	ChangeVolume(MODE_PWM, INIT_VOL_PWM);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	ChangeVolume(u8_t mode, vol_t volume)
{
	double	step;

	volume = volume < TIMx_ARR_VAL ? volume : TIMx_ARR_VAL;
	switch (mode)
	{
		case MODE_SIN:
			step = 360 / PERIOD_SIG;
			for (size_t i = 0; i < PERIOD_SIG; ++i)
				SinSig[i] = (sin(i * step * M_PI / 180) + 1) / 2 * volume;
			break;

		case MODE_SQR:
			for (size_t i = 0; i < PERIOD_SIG; ++i)
			{
				if (i < PERIOD_SIG / 2)
					SqrSig[i] = volume;
				else
					SqrSig[i] = 0;
			}
			break;

		case MODE_PWM:
			PwmSig[0] = volume;
			break;
		
		default:
			return ;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	PlaySoundRawFrq(u16_t frq, dur_t duration_ms, u8_t mode)
{
	if (mode >= NOT_VALID)
		return ;

	signal_t	*sigs[] = {SinSig, SqrSig, PwmSig};

	SetCIRCModeDMA();
	TIMx_ARR = TIMx_ARR_VAL;
	if (mode == MODE_PWM)
		TIMx_PSC = (double)TIM_FRQ / ((TIMx_ARR + 1) * frq);
	else
		TIMx_PSC = (double)TIM_FRQ / (PERIOD_SIG * (TIMx_ARR + 1) * frq);
	if (mode == MODE_PWM)
		TIMx_CCR = PwmSig[0];

	if (mode == MODE_PWM)
		PWM_Start((u32_t *)sigs[mode], 1);
	else
		PWM_Start((u32_t *)sigs[mode], PERIOD_SIG);
	Duration(duration_ms);
	PWM_Stop();
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	PlaySound(u8_t frq, dur_t duration_ms, u8_t mode)
{
	if (mode >= NOT_VALID)
		return ;

	signal_t	*sigs[] = {SinSig, SqrSig, PwmSig};
	double		notes[] = {C, C_, D, D_, E, F ,F_ ,G , G_, A, A_, B};
	u16_t		hz = notes[frq & 0xF] * (1 << ((frq & 0xF0) >> 4));

	SetCIRCModeDMA();
	TIMx_ARR = TIMx_ARR_VAL;
	if (mode == MODE_PWM)
		TIMx_PSC = (double)TIM_FRQ / ((TIMx_ARR + 1) * hz);
	else
		TIMx_PSC = (double)TIM_FRQ / (PERIOD_SIG * (TIMx_ARR + 1) * hz);
	if (mode == MODE_PWM)
		TIMx_CCR = PwmSig[0];

	if (mode == MODE_PWM)
		PWM_Start((u32_t *)sigs[mode], 1);
	else
		PWM_Start((u32_t *)sigs[mode], PERIOD_SIG);
	Duration(duration_ms);
	PWM_Stop();
}
