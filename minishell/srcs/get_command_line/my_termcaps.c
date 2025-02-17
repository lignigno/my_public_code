/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:53:57 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:53:57 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	backspace(char *str)
{
	str[ft_strlen(str) - 1] = '\0';
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("dc", NULL), 1, ft_putchar);
}

void	save_cursor_position(void)
{
	tputs(save_cursor, 1, ft_putchar);
}

void	reset_cursor_position(void)
{
	tputs(restore_cursor, 1, ft_putchar);
}

void	clear_after_cursor(void)
{
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
}
