/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_errorka.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:51:56 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:51:57 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static void	error_with_what(char *error, char *what)
{
	write(2, what, ft_strlen(what));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

// ________________________________________________________________MAIN FUNCTION

void	minishell_errorka(char *error, char *what)
{
	write(2, "minishell: ", 11);
	if (what)
		error_with_what(error, what);
	else
	{
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
}
