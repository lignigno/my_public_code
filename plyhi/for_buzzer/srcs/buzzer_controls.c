/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:53:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/04 23:07:44 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"
#include "user_func.h"
#include <math.h>

// _____________________________________________________________________________

// void  Sart_DMA(uint32_t *pData, uint16_t Length)
// {
// 	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)pData, Length);
// }

// void  Stop_DMA(void)
// {
//   HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
// }

// // _____________________________________________________________________________

// void  SetSound(uint64_t hz, uint8_t volume)
// {
// 	volume = volume < 101 ? volume : 100;

// 	DMA1_Channel2->CCR |= DMA_CCR_CIRC;
// 	TIM1->ARR = 79;
// 	TIM1->PSC = MKHz / (LEN_SINGNAL * TIM1->ARR * hz);

// 	singleSignal[0] = volume;
// 	Sart_DMA((uint32_t *)singleSignal, LEN_SINGNAL);
// }

// void  UnSetSound(void)
// {
// 	Stop_DMA();
// }

// void	pilick(uint8_t count, uint8_t volume)
// {
// 	for(size_t i = 0; i < count; ++i)
// 	{
// 	  SetSound(500, volume);
// 	  HAL_Delay(300);
// 	  UnSetSound();
// 	  HAL_Delay(100);
// 	}
// }

// _____________________________________________________________________________

void	InitSound(hz_t *sound, u64_t arr_size)
{
	size_t i = sizeof(duration_t);

	--arr_size;
	while (i < arr_size)
	{
		sound[i] = NOT_NOTE;
		++i;
	}
	sound[i] = END_SOUND;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	SetDuration(hz_t *sound, duration_t duration)
{
	u8_t	i;
	u8_t	size;
	u8_t	offset;

	size = sizeof(duration_t) - 1;
	i = 0;
	while (i <= size)
	{
		offset = (size - i) * 8;
		sound[i] = (duration & (0xFF << offset)) >> offset;
		++i;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	AddFrequency(hz_t *sound, double hz)
{
	size_t	i;
	double	note;
	double	base_note[] = {17, 18, 19, 20, 21, 23, 24, 25, 27, 29, 30, 31};

	i = sizeof(duration_t);
	while (sound[i] < RESERVED)
		++i;
	if (sound[i] == END_SOUND)
		return ;
	for (size_t octave = 0; octave < 10; ++octave)
	{
		note = hz / (1 << octave);
		if (note < 31.5)
		{
			sound[i] = octave * 12;
			for (u8_t num_note = 0; num_note < 12; ++num_note)
			{
				if (note < base_note[num_note])
				{
					sound[i] += num_note;
					sound[i] = sound[i] > 47 ? sound[i] : 48;
					return ;
				}
			}
		}
	}
	sound[i] = 119;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	RemoveFrequency(hz_t *sound, u64_t position)
{
	size_t i;

	i = sizeof(duration_t);
	position += i;
	while (sound[i] < RESERVED && position != i)
		++i;
	if (sound[i] > RESERVED - 1)
		return ;
	while (sound[i] < RESERVED)
	{
		sound[i] = sound[i + 1];
		++i;
	}
	if (sound[i] == END_SOUND)
		sound[i - 1] = NOT_NOTE;
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	preparing(const hz_t *sound)
{
	double	notes[] = {C, C_, D, D_, E, F, F_, G, G_, A, A_, B};
	double	sfa = SIZE_FREQUENCY_ARR;
	double	curHz;
	double	step;
	double	resulting_amplitude;
	int		last_res;

	for (size_t i = 0; i < sfa; ++i)
	{
		resulting_amplitude = 0;
		for (size_t hz = sizeof(duration_t); sound[hz] < RESERVED; ++hz)
		{
			curHz = (notes[sound[hz] % 12]) * (1 << (sound[hz] / 12));	// берём составляющую частоту
			step = 360 / (DATA_OUTPUT_Hz / curHz);						// вычисляем шаг
			resulting_amplitude += sin(step * i * M_PI / 180);			// накладываем волы
		}
		last_res = (resulting_amplitude) * AMPLITUDE + TIMx_ARR / 2;
		last_res = last_res < TIMx_ARR ? last_res : TIMx_ARR;
		last_res = last_res > 0 ? last_res : 0;
		FrequencyArr[i] = last_res;
		printf("{%*s} %4zu%*s| %f\n", FrequencyArr[i], "", i, TIMx_ARR - FrequencyArr[i], "", resulting_amplitude);
	}
	
}

void	PlaySound(const hz_t *sound)
{
	preparing(sound);
	printf("\nI play:)\n");
}
