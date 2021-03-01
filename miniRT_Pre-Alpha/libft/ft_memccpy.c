/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:38:05 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 19:38:27 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int chr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)chr)
			return ((unsigned char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
