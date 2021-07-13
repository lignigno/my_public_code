/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:30:04 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/07 21:13:07 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// __________________________________________________________________SUBFUNCTION

static int	ft_putnbr_in_dst(char *dst, int position, size_t n)
{
	int		len;
	int		i;
	char	buff;

	len = 0;
	while (n || len == 0)
	{
		dst[position] = n % 10 + '0';
		position++;
		n = n / 10;
		len++;
	}
	i = 1;
	while (i - 1 < len + 1 / 2)
	{
		buff = dst[position - len];
		dst[position - len] = dst[position - i];
		dst[position - i] = buff;
		len--;
		i++;
	}
	dst[position] = '\0';
	return (position);
}

// ____________________________________________________________________MAIN FUNC

void	logs(t_v *v, int seat_number, char *movement)
{
	char	msg[50];
	int		i;
	int		j;

	i = ft_putnbr_in_dst(msg, 0, get_time() - v->start_time);
	msg[i++] = ' ';
	i = ft_putnbr_in_dst(msg, i, seat_number);
	msg[i++] = ' ';
	j = 0;
	while (movement[j])
	{
		msg[i] = movement[j];
		j++;
		i++;
	}
	msg[i++] = '\n';
	msg[i] = '\0';
	sem_wait(v->program_sem[WRITE_SEM]);
	write(1, msg, i);
	sem_post(v->program_sem[WRITE_SEM]);
}
