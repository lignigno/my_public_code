/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:26:03 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 22:26:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*result;

	result = (char*)malloc(ft_strlen(s1) + 1);
	if (!result)
		return (NULL);
	i = ft_strlen(s1) + 2;
	while (--i > 0)
		result[i - 1] = s1[i - 1];
	return (result);
}
