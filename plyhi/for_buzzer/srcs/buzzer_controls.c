/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:53:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/02 10:46:53 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"
#include "user_func.h"

// _____________________________________________________________________________

void  Sart_DMA(uint32_t *pData, uint16_t Length)
{
	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)pData, Length);
}

void  Stop_DMA(void)
{
  HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
}

// _____________________________________________________________________________

void  SetSound(uint64_t hz, uint8_t volume)
{
	volume = volume < 101 ? volume : 100;

	DMA1_Channel2->CCR |= DMA_CCR_CIRC;
	TIM1->ARR = 100;
	TIM1->PSC = MKHz / (LEN_SINGNAL * TIM1->ARR * hz);

	singleSignal[0] = volume;
	Sart_DMA((uint32_t *)singleSignal, LEN_SINGNAL);
}

void  UnSetSound(void)
{
	Stop_DMA();
}

void	pilick(uint8_t count, uint8_t volume)
{
	for(size_t i = 0; i < count; ++i)
	{
	  SetSound(500, volume);
	  HAL_Delay(300);
	  UnSetSound();
	  HAL_Delay(100);
	}
}
