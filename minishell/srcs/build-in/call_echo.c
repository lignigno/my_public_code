/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:51 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 09:59:42 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	call_echo(t_command *command)
{
	int	new_line;
	int	word;
	int	i;

	new_line = 1;
	word = 0;
	i = 1;
	while (command->argv[i])
	{
		if (!ft_strcmp(command->argv[i], "-n") && !word)
			new_line = 0;
		else
		{
			word = 1;
			write(1, command->argv[i], ft_strlen(command->argv[i]));
			if (command->argv[i + 1])
				write(1, " ", 1);
		}
		i++;
	}
	if (new_line)
		write(1, "\n", 1);
	exit(0);
}
