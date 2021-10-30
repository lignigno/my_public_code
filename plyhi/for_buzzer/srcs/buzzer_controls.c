/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:53:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/30 12:26:18 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"

void	setSound(u64_t hz, u8_t volume)
{
    // TIM_OC_InitTypeDef sConfigOC;

	volume = volume < 100 ? volume : 99;

	// you reconfigs

	// set bit for circular dma
	// DMA->CCR2 |= CIRC;

	// set Period in 100
	// htim1.Init.Period = 99;

	// prescaler = MCHz / Period / hz
	/*
		короче... я знаю на какой частоте работает таймер мк и
		просто поставлю частоту через свой define
		хоть и знаю что можно через собрать весь путь от HSE
		до шины на которой работает таймер
	*/
	// htim1.Init.Prescaler = MC_Hz / htim1.Init.Period / hz;

	// if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
	// {
	// 	Error_Handler();
	// }

	// sConfigOC.Pulse = volume;

	// if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	// {
	// 	Error_Handler();
	// }
}
