/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:51:11 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:51:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// ________________________________________________________________MAIN FUNCTION

void	call_exit(t_all_var *all)
{
	unset_keypress(all->term_settings);
	write(all->save_stdout, "exit\n", 5);
	exit(0);
}
