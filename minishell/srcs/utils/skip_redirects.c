/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:01:38 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:01:38 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

size_t	skip_redirects(char *str, size_t i, int mark, int slash)
{
	if (str[i + 1] == '>')
		i++;
	i = skip_spaces(str, i + 1);
	while (str[i])
	{
		if (!slash && mark == str[i])
			mark = 0;
		else if (!mark && !slash && (str[i] == '\'' || str[i] == '\"'))
			mark = str[i];
		else if (mark != '\'' && str[i] == '\\' && str[i + 1])
			i++;
		else if (!mark && compare_char_with(" |;", str[i]))
			break ;
		i++;
	}
	return (i);
}
