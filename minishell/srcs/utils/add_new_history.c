/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:04 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:58:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	add_new_history(t_all_var *all, char *command_line)
{
	t_history	*new_history;

	new_history = malloc(sizeof(t_history));
	if (new_history == NULL)
		errorka(all, NMA_HISTORI);
	new_history->command_line = command_line;
	new_history->cursor = ft_strlen(command_line);
	new_history->next = all->history;
	new_history->back = NULL;
	if (all->history != NULL)
		all->history->back = new_history;
	all->history = new_history;
}
