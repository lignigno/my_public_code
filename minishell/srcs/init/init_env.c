/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:56:47 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:56:48 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// ________________________________________________________________MAIN FUNCTION

t_env	*init_env(t_all_var *all, char **env, int sorting)
{
	t_env	*result;
	size_t	i;

	i = 0;
	result = NULL;
	while (env[i])
	{
		if (sorting == ON)
			add_with_sorting(all, env[i], &result);
		else
			add_without_sorting(all, env[i], &result);
		i++;
	}
	return (result);
}
