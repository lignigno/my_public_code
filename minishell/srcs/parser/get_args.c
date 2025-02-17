/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:10:50 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:10:51 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static void	*free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

static int	init_this(char *str, size_t i, char ***result, size_t *count)
{
	size_t	j;

	*count = count_args(str, i);
	*result = malloc(*count * sizeof(char *) + 1);
	if (!*result)
		return (0);
	j = 0;
	while (j <= *count)
		(*result)[j++] = NULL;
	return (1);
}

char	**get_args(char *str, size_t i)
{
	size_t	j;
	size_t	count;
	char	**result;

	if (!init_this(str, i, &result, &count))
		return (NULL);
	j = 0;
	while (j < count)
	{
		while (str[i])
		{
			i = skip_spaces(str, i);
			if (str[i] == '<' || str[i] == '>')
				i = skip_redirects(str, i, 0, 0);
			else
				break ;
		}
		result[j] = get_one_arg(str, &i);
		if (!result[j])
			return (free_args(result));
		j++;
	}
	result[count] = NULL;
	return (result);
}
