/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:32:15 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 22:32:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last;
	int		flag;

	flag = 0;
	last = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			last = i;
			flag = 1;
		}
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char*)&s[i]);
	if (flag)
		return ((char*)&s[last]);
	return (NULL);
}
