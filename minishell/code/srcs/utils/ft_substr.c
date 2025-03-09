/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:00:49 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:00:49 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
