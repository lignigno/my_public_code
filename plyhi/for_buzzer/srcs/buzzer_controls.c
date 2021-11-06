/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:53:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/06 07:54:22 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"

// _____________________________________________________________________________

void	InitSound(void)
{
	ChangeVolume(MODE_SIN, 0);
	ChangeVolume(MODE_SQR, 0);
	ChangeVolume(MODE_PWM, 0);
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
				SinSig[i] = (sin(i * step * M_PI / 180) + 1) * volume;
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

void	PlaySound(u16_t hz, u32_t duration_ms, u8_t mode)
{
	if (mode >= NOT_VALID)
		return ;

	signal_t	*sigs[] = {SinSig, SqrSig, PwmSig};

	SetCIRCModeDMA();
	TIMx_ARR = TIMx_ARR_VAL;
	if (mode == MODE_PWM)
		TIMx_PSC = MC_Hz / ((TIMx_ARR + 1) * hz);
	else
		TIMx_PSC = MC_Hz / (PERIOD_SIG * (TIMx_ARR + 1) * hz);
	if (mode == MODE_PWM)
		; // pulse = PwmSig[0];

	if (mode == MODE_PWM)
		PWM_Start((u32_t *)sigs[mode], 1);
	else
		PWM_Start((u32_t *)sigs[mode], PERIOD_SIG);
	Duration(duration_ms);
	PWM_Stop();
}
