/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:51:18 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:51:18 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// __________________________________________________________________SUBFUNCTION

static int	write_exp(t_all_var *all)
{
	t_env	*iterator;

	iterator = all->exp;
	while (iterator)
	{
		write(1, iterator->variable, ft_strlen(iterator->variable));
		if (!iterator->value)
			write(1, "\n", 1);
		else
		{
			write(1, "=\"", 2);
			write(1, iterator->value, ft_strlen(iterator->value));
			write(1, "\"\n", 2);
		}
		iterator = iterator->next;
	}
	return (0);
}

// ________________________________________________________________MAIN FUNCTION

int	call_export(t_all_var *all, t_command *command)
{
	int	exit_code;
	int	i;

	exit_code = 0;
	if (!command->argv[1])
		return (write_exp(all));
	i = 0;
	while (command->argv[++i])
	{
		if (not_valid_identifier(all, "export", command->argv[i], &exit_code))
			continue ;
		add_with_sorting(all, command->argv[i], &all->exp);
		add_without_sorting(all, command->argv[i], &all->env);
	}
	return (exit_code);
}
