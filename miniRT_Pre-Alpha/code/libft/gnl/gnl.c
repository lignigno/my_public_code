/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:44:21 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/19 18:52:07 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static int	initial_settings(int fd, char **line, int *readed, char **result)
{
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (0);
	if ((*result = malloc(sizeof(char))) == NULL)
		return (0);
	**result = '\0';
	*readed = 1;
	return (1);
}

static int	collect_string(int fd, int *readed, \
							t_buff_memory *buff, char **result)
{
	while (*readed > 0)
	{
		*result = concat(*result, &buff->str[buff->start]);
		if (*result == NULL)
			return (-1);
		if (found_new_line(buff))
			break ;
		*readed = read(fd, buff->str, BUFFER_SIZE);
		buff->str[*readed > 0 ? *readed : 0] = '\0';
	}
	return (*readed);
}

int			gnl(int fd, char **line)
{
	static t_buff_memory	buff[1024];
	int						readed;
	char					*result;
	int						success;

	success = initial_settings(fd, line, &readed, &result);
	if (!success)
		return (-1);
	success = collect_string(fd, &readed, &buff[fd], &result);
	success = success < 0 ? 0 : 1;
	if (!success)
		return (err_exit(result, &buff[fd]));
	readed = readed > 1 ? 1 : readed;
	*line = result;
	return (readed);
}
