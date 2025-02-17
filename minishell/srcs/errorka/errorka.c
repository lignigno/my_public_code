/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:51:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 14:00:26 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	errorka(t_all_var *all, char *error_str)
{
	all->last_exit_code = 1;
	write(2, "\e[38;2;176;16;16;1m\n", 20);
	write(2, error_str, ft_strlen(error_str));
	write(2, "\n\e[m", 4);
	exit(all->last_exit_code);
}
