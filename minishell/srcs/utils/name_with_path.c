/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_with_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:01:13 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 12:01:14 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// ________________________________________________________________MAIN FUNCTION

int	name_with_path(char *name)
{
	size_t	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
