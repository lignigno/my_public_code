/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:40:01 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 19:40:05 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cop_s1;
	unsigned char	*cop_s2;

	cop_s1 = (unsigned char*)s1;
	cop_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (cop_s1[i] != cop_s2[i])
			return (((int)cop_s1[i]) - ((int)cop_s2[i]));
		++i;
	}
	return (0);
}
