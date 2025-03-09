/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:33:01 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 22:33:05 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dbl_while_rl(char const *str1, char const *str2)
{
	size_t	i;
	size_t	j;
	size_t	min1;
	size_t	min2;

	i = ft_strlen(str1);
	min1 = 0;
	min2 = 0;
	while (i > min1)
	{
		j = ft_strlen(str2);
		while (j > min2)
		{
			if (str1[i - 1] == str2[j - 1])
				break ;
			--j;
		}
		if (j == min2)
			return (i);
		--i;
	}
	return (i);
}

static int	dbl_while_lr(char const *str1, char const *str2)
{
	size_t	i;
	size_t	j;
	size_t	max1;
	size_t	max2;

	max1 = ft_strlen(str1);
	max2 = ft_strlen(str2);
	i = 0;
	while (i < max1)
	{
		j = 0;
		while (j < max2)
		{
			if (str1[i] == str2[j])
				break ;
			++j;
		}
		if (j == max2)
			return (i);
		++i;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = dbl_while_lr(s1, set);
	j = dbl_while_rl(s1, set);
	if (i > j)
	{
		result = (char*)malloc(1);
		result[0] = '\0';
		return (result);
	}
	result = (char*)malloc(j - i + 1);
	if (result == NULL)
		return (NULL);
	start = i;
	while (++i - 1 < j)
		result[i - start - 1] = s1[i - 1];
	result[i - start - 1] = '\0';
	return (result);
}
