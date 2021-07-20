/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:43:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/20 21:49:20 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

int	finish(t_v *v)
{
	pthread_mutex_lock(&v->write_mutex);
	write(2, FINISH_COLOR, ft_strlen(FINISH_COLOR));
	ft_putnbr(get_time() - v->start_time, 2);
	write(2, " finish\n\033[m", 11);
	return (1);
}
