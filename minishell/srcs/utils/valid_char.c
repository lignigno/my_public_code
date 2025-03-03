/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:01:51 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:01:51 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int	valid_char(char ch, size_t i)
{
	if ((ch == '_')
		|| ('0' <= ch && ch <= '9' && i > 0)
		|| ('a' <= ch && ch <= 'z')
		|| ('A' <= ch && ch <= 'Z'))
		return (1);
	return (0);
}
