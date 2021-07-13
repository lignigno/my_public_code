/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorka_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:19:18 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/08 00:59:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

// ____________________________________________________________________MAIN FUNC

long	errorka_0(char *error_message, int ret_value)
{
	write(2, ERROR_COLOR, ft_strlen(ERROR_COLOR));
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n\033[m", 4);
	return (ret_value);
}
