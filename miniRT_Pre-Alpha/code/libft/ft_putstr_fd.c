/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:43:47 by lignigno          #+#    #+#             */
/*   Updated: 2020/12/18 08:34:44 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	len = 0;
	if (s != NULL)
		len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		write(fd, ((unsigned char*)(s + i)), 1);
		i++;
	}
}
