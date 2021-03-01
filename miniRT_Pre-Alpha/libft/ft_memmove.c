/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:41:17 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 19:41:23 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst < src)
	{
		i = 0;
		while (i < len && (dst || src))
		{
			*((char*)dst + i) = *((char*)src + i);
			++i;
		}
	}
	else
	{
		i = len;
		while (i > 0 && (dst || src))
		{
			--i;
			*((char*)dst + i) = *((char*)src + i);
		}
	}
	return ((char*)dst);
}
