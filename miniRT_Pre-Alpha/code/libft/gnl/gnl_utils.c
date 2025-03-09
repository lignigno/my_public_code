/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:12:18 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/18 04:45:23 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	len_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*concat(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = malloc((len_str(dst) + len_str(src)) * sizeof(char) + 1);
	if (result == NULL)
	{
		free(dst);
		return (NULL);
	}
	i = -1;
	while (dst[++i] != '\0')
		result[i] = dst[i];
	j = 0;
	while (src[j] != '\0' && src[j] != '\n')
	{
		result[i + j] = src[j];
		j++;
	}
	result[i + j] = '\0';
	free(dst);
	return (result);
}

int		found_new_line(t_buff_memory *buff)
{
	int	offset;

	offset = 0;
	while (buff->str[buff->start + offset] != '\0')
	{
		if (buff->str[buff->start + offset] == '\n')
		{
			buff->start += offset + 1;
			return (1);
		}
		offset++;
	}
	buff->start = 0;
	return (0);
}

int		err_exit(char *result, t_buff_memory *buff)
{
	int	i;

	if (result != NULL)
		free(result);
	i = 0;
	while (i < BUFFER_SIZE)
		buff->str[i++] = '\0';
	return (-1);
}
