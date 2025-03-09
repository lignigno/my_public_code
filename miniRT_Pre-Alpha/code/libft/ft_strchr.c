/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:45:12 by lignigno          #+#    #+#             */
/*   Updated: 2020/12/15 04:05:48 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
