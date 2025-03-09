/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_existing_variable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:35 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 11:58:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int	change_existing_variable(t_all_var *all, t_env *env, t_env *list)
{
	t_env	*required_variable;
	char	*tmp;

	required_variable = get_variable(list, env->variable);
	if (env->value)
	{
		if (required_variable->value && env->next)
			tmp = ft_strjoin(required_variable->value, env->value);
		else
			tmp = env->value;
		if (!tmp)
			errorka(all, NMA_ENV);
		if (required_variable->value)
			free(required_variable->value);
		required_variable->value = tmp;
		free(env->variable);
		free(env);
	}
	else
	{
		free(env->variable);
		free(env);
	}
	return (1);
}
