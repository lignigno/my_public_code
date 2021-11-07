/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users_wrapers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 05:26:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/07 16:52:32 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"

// you timer for pwm
// extern TIM_HandleTypeDef htim1;
// I use DMA
// extern DMA_HandleTypeDef hdma_tim1_ch1;

// need only for dma
void	SetCIRCModeDMA(void)
{
	// DMA1_Channel2->CCR |= DMA_CCR_CIRC;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	PWM_Start(u32_t *pData, u16_t Length)
{
	/*
	** if you don't want to use dma
	** example :
	** (void)pData;
	** (void)Length;
	** HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	*/

	// HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (u32_t *)pData, Length);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	PWM_Stop(void)
{
	// HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	Duration(dur_t duration)
{
	// HAL_Delay(duration);
}
