/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:43:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 04:48:16 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

int	finish(t_v *v, int seat_number)
{
	pthread_mutex_lock(&v->write_mutex);
	write(2, FINISH_COLOR, ft_strlen(FINISH_COLOR));
	ft_putnbr(get_time() - v->start_time, 2);
	write(2, " ", 1);
	ft_putnbr(seat_number, 2);
	write(2, " ", 1);
	write(2, "finish", ft_strlen("finish"));
	write(2, "\n\033[m", 4);
	return (1);
}
