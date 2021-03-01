/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:27:20 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/10 11:49:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	if (dstsize == 0)
		return (len_dst + len_src);
	i = 0;
	while (i < dstsize - len_dst - 1 && src[i] != '\0')
	{
		dst[i + len_dst] = src[i];
		++i;
	}
	dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}
