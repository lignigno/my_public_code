/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:53:42 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/19 18:52:13 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct	s_buff_memory
{
	char	str[BUFFER_SIZE + 1];
	int		start;
}				t_buff_memory;

int				gnl(int fd, char **line);
int				found_new_line(t_buff_memory *buff);
int				err_exit(char *result, t_buff_memory *buff);
char			*concat(char *dst, char *src);
size_t			len_str(char *str);

#endif
