/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:01:19 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:01:20 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static char	*get_variable_from_str(char *str)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len] && !compare_char_with("+=", str[len]))
		len++;
	result = malloc(len *sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*escaping(char *str, char *result, size_t len, size_t i)
{
	size_t	start;
	size_t	j;

	start = i - len;
	i = 0;
	j = 0;
	while (i < len)
	{
		if (compare_char_with("\\\"$", str[start + j])
			&& str[start + j - 1] != '\\')
		{
			result = add_char(result, '\\', i++);
			if (!result)
				return (result);
			result[i] = str[start + j];
			len++;
		}
		else
			result[i] = str[start + j];
		i++;
		j++;
	}
	result[len] = '\0';
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	*get_value_from_str(char *str, int *append)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	while (str[i] && !compare_char_with("+=", str[i]))
		i++;
	if (!str[i])
		return ((char *)1);
	len = 0;
	*append = str[i] == '+';
	i += 1 + (str[i] == '+');
	while (str[i])
		len += !!++i;
	result = malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	result = escaping(str, result, len, i);
	return (result);
}

// ________________________________________________________________MAIN FUNCTION

t_env	*new_env(t_all_var *all, char *str)
{
	t_env	*result;
	int		append;

	append = 0;
	result = malloc(sizeof(t_env));
	if (result == NULL)
		errorka(all, NMA_ENV);
	result->variable = get_variable_from_str(str);
	result->value = get_value_from_str(str, &append);
	if (!result->variable || !result->value)
		errorka(all, NMA_ENV);
	if (result->value == (char *)1)
		result->value = NULL;
	if (append)
		result->next = (void *)1;
	else
		result->next = NULL;
	return (result);
}
