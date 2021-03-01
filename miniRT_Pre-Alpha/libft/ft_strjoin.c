/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:26:48 by lignigno          #+#    #+#             */
/*   Updated: 2020/12/18 06:15:18 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char*)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (++i < len1 + 1)
		result[i - 1] = s1[i - 1];
	i = 0;
	while (++i < len2 + 1)
		result[len1 + i - 1] = s2[i - 1];
	result[len1 + i - 1] = '\0';
	return (result);
}
