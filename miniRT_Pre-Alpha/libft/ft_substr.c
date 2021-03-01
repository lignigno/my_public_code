/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:33:38 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 22:33:40 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	result = (char*)malloc(len + 1);
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
