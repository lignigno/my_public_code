/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:43:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/13 00:35:00 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

void	finish(t_v *v)
{
	sem_wait(v->program_sem[WRITE_SEM]);
	write(1, FINISH_COLOR, ft_strlen(FINISH_COLOR));
	ft_putnbr(get_time() - v->start_time, 1);
	write(1, " finish\033[m\n", 11);
}
