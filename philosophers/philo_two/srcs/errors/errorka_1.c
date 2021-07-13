/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:39:25 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 00:59:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

long	errorka_1(char *what_wrong, char *variable, char *value)
{
	write(2, ERROR_COLOR, ft_strlen(ERROR_COLOR));
	write(2, what_wrong, ft_strlen(what_wrong));
	write(2, " :\n\tvariable : {", 16);
	write(2, variable, ft_strlen(variable));
	write(2, "}\n\tvalue    : {", 16);
	write(2, value, ft_strlen(value));
	write(2, "}\n\033[m", 5);
	return (0);
}
