/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:02:53 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/20 21:43:54 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

void	errorka_2(t_v *v, t_chair *place)
{
	pthread_mutex_lock(&v->write_mutex);
	write(2, ERROR_COLOR, ft_strlen(ERROR_COLOR));
	ft_putnbr(get_time() - place->start_time, 2);
	write(2, " ", 1);
	ft_putnbr(place->seat_number, 2);
	write(2, " died\n\033[m", 9);
	v->each_must_eat = 0;
}
