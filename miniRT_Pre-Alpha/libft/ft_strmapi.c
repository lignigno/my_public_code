/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:29:25 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 22:29:59 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (--len + 1)
		result[len] = f(len, s[len]);
	return (result);
}
