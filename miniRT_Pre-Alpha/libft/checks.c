/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:37:38 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/23 08:40:12 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			checks(char *str, int start)
{
	static int	check_point_n;
	int			len;

	if (start)
		check_point_n = 0;
	check_point_n++;
	if (str == NULL)
		str = "unknown_";
	len = ft_strlen(str);
	write(1, str, len);
	write(1, "_check_", 6);
	ft_putnbr_fd(check_point_n, 1);
	write(1, "\n", 1);
}
