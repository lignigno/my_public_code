/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:47:22 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/04 00:45:08 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buzzer.h"

#define sound_size INIT_SOUND_SIZE(5)

void	ShowSound(hz_t *sound)
{
	for (size_t i = 0; i < sound_size; i++)
	{
		printf("|");
		if (i < sizeof(duration_t) || i == sound_size - 1) printf("\e[1;38;2;;200;200m");
		printf("%5zu", i);
		if (i < sizeof(duration_t) || i == sound_size - 1) printf("\e[m");
	}
	printf("|\n");

	for (size_t i = 0; i < sound_size; i++)
	{
		printf("|");
		if (i < sizeof(duration_t) || i == sound_size - 1) printf("\e[1;38;2;;200;200m");
		if (sound[i] == NOT_NOTE)
			printf("  X  ");
		else
			printf("%5u", sound[i]);
		if (i < sizeof(duration_t) || i == sound_size - 1) printf("\e[m");
	}
	printf("|\n");
}

int	main(void)
{
	hz_t	sound[sound_size];

	sound[0] = 42;
	sound[1] = 21;
	InitSound(sound, sound_size);
	SetDuration(sound, 1000);
	AddFrequency(sound, G * (1 << 5));
	AddFrequency(sound, F * (1 << 5));
	AddFrequency(sound, G * (1 << 5));
	AddFrequency(sound, F * (1 << 5));
	AddFrequency(sound, G * (1 << 5));

	ShowSound(sound);

	PlaySound(sound);
	return 0;
}
