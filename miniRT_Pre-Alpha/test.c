/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:52:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 00:56:14 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project_header.h"

#define FUCKIN_SUPER_ERROR "fuckin super error : bla-bla-bla bla-bla-bla bla-bla-bla bla-bla-bla \
bla-bla-bla bla-bla-bla bla-bla-bla bla-bla-bla bla-bla-bla bla-bla-bla bla-bla-bla \
bla-bla-bla Unicorn)\n"

void		super_error(t_vars *vars, char *error)
{
	int		error_string_length;

	error_string_length = ft_strlen(error);
	write(2, "\033[31mError\n\n", 12);
	write(2, error, error_string_length);
	exit(0);
}

int main(int argc, char const *argv[])
{
	t_vars vars;
	super_error(&vars, FUCKIN_SUPER_ERROR);
}
