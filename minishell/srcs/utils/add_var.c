/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:12 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 14:56:32 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	add_var(t_all_var *all, const char *variable, char *value)
{
	char	*result;
	char	*tmp;

	result = ft_strdup(variable);
	if (!result)
		errorka(all, NMA_ENV);
	if (value)
	{
		result = add_char(result, '=', -1);
		if (!result)
			errorka(all, NMA_ENV);
		tmp = result;
		result = ft_strjoin(result, value);
		if (!tmp)
			errorka(all, NMA_ENV);
		free(tmp);
		free(value);
	}
	add_with_sorting(all, result, &all->exp);
	if (value)
		add_without_sorting(all, result, &all->env);
	free(result);
}
