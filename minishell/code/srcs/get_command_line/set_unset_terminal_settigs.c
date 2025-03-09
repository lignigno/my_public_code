/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_unset_terminal_settigs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:04 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:54:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	set_keypress(struct termios stored_settings)
{
	stored_settings.c_lflag &= (~ICANON & ~ECHO & ~ISIG);
	stored_settings.c_cc[VTIME] = 0;
	stored_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &stored_settings);
}

void	unset_keypress(struct termios stored_settings)
{
	tcsetattr(0, TCSANOW, &stored_settings);
}
