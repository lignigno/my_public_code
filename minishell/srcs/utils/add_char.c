/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:57:57 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:57:58 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

/*
** if (index > size_str || index < 0)
** index = last;
*/
char	*add_char(char *str, char ch, size_t index)
{
	size_t	i;
	size_t	size;
	char	*result;

	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	result = (char *)malloc(size * sizeof(char) + 2);
	if (result == NULL)
		return (NULL);
	if (index > size)
		index = size;
	i = 0;
	while (i < size + 1)
	{
		if (i == index)
			result[index] = ch;
		else
			result[i] = str[i - (index < i)];
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}
