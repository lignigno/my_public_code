/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 08:15:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/05 18:39:39 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// _________________________________________________________________MAIN FUNTION
// ___________________________________________________________________PRINT BITS

void	print_bits(char ch, int offset, int change, char *color, int size_char)
{
	char	bit;
	int		i;
	
	i = 0;
	while (i < size_char * 8)
	{
		bit = (ch & 0x80) >> (size_char * 8 - 1);
		if (i == change)
			fprintf(stderr, "%s%c\033[m", CHANGE, bit + '0');
		else if (size_char * 8 - i > offset)
			fprintf(stderr, "%s%c\033[m", color, bit + '0');
		else
			fprintf(stderr, "%s%c\033[m", OFFSET, bit + '0');
		ch <<= 1;
		i++;
	}
}

// _________________________________________________________________MAIN FUNTION
// ____________________________________________________________________FT STRLEN

size_t	ft_strlen_end_char(const char *str, char end_char)
{
	size_t	len;

	len = 0;
	while (str[len] != end_char)
		len++;
	return (len);
}

// _________________________________________________________________MAIN FUNTION
// _____________________________________________________________________ADD CHAR

/*
** if (index > size_str || index < 0)
** index = last;
*/
char	*add_char(char *str, char ch, size_t index)
{
	size_t	i;
	size_t	size;
	char	*result;

	if (str == NULL)
		return (NULL);
	size = ft_strlen_end_char(str, END_CHARACTER);
	result = (char *)malloc(size * sizeof(char) + 2);
	if (result == NULL)
		return (NULL);
	if (index > size)
		index = size;
	i = 0;
	while (i < size + 1)
	{
		if (i == index)
			result[index] = ch;
		else
			result[i] = str[i - (index < i)];
		i++;
	}
	result[i] = END_CHARACTER;
	free(str);
	return (result);
}