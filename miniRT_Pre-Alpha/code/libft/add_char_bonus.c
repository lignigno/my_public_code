/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:27:22 by lignigno          #+#    #+#             */
/*   Updated: 2020/12/18 08:33:02 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_char_back(char *str, char ch)
{
	size_t	i;
	size_t	size;
	char	*result;

	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	result = (char*)malloc(size + 2);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = ch;
	result[i] = '\0';
	free(str);
	return (result);
}

char	*add_char_front(char *str, char ch)
{
	size_t	i;
	size_t	size;
	char	*result;

	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	result = (char*)malloc(size + 2);
	if (result == NULL)
		return (NULL);
	result[0] = ch;
	i = 0;
	while (i < size)
	{
		result[i + 1] = str[i];
		i++;
	}
	result[i + 1] = '\0';
	free(str);
	return (result);
}
