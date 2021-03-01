/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:44:33 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 19:44:43 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**destroy_ft_split(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static size_t	counting_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && flag == 1)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count + 1);
}

static size_t	find_end(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	return (j);
}

static char		**eviscerator(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	*str;

	k = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			j = find_end(s, c, i);
			str = ft_substr(s, i, j);
			if (str == NULL)
				return (NULL);
			arr[k++] = str;
			i += j - 1;
			j = 0;
		}
	}
	arr[k] = NULL;
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = counting_words(s, c);
	arr = (char**)malloc(size * sizeof(char*));
	if (arr == NULL)
		return (NULL);
	arr = eviscerator(arr, s, c);
	if (arr == NULL)
		return (destroy_ft_split(arr, size));
	return (arr);
}
