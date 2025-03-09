/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:51:24 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:51:24 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	call_pwd(void)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	write(1, current_dir, ft_strlen(current_dir));
	write(1, "\n", 1);
	exit(0);
}
