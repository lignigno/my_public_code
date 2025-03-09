/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:51:31 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 09:43:23 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static void	cut(t_all_var *all, t_env *iterator, t_env *tmp, int exp)
{
	if (exp)
	{
		if (all)
			all->exp = iterator;
		else
			iterator->next = tmp->next;
		free(tmp->variable);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	else
	{
		if (all)
			all->env = iterator;
		else
			iterator->next = tmp->next;
		free(tmp->variable);
		free(tmp->value);
		free(tmp);
	}
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

void	unset(t_all_var *all, char *need_unset, t_env *exp, t_env *env)
{
	t_env	*iterator_exp;
	t_env	*iterator_env;

	if (all->exp && !ft_strcmp(all->exp->variable, need_unset))
		cut(all, all->exp->next, all->exp, 1);
	if (all->env && !ft_strcmp(all->env->variable, need_unset))
		cut(all, all->env->next, all->env, 0);
	iterator_exp = all->exp;
	iterator_env = all->env;
	while ((all->exp && iterator_exp->next) || (all->env && iterator_env->next))
	{
		exp = iterator_exp->next;
		env = iterator_env->next;
		if (exp && !ft_strcmp(exp->variable, need_unset))
			cut(NULL, iterator_exp, exp, 1);
		else if (iterator_exp->next)
			iterator_exp = iterator_exp->next;
		if (env && !ft_strcmp(env->variable, need_unset))
			cut(NULL, iterator_env, env, 0);
		else if (iterator_env->next)
			iterator_env = iterator_env->next;
	}
	free(need_unset);
}

// ________________________________________________________________MAIN FUNCTION

int	call_unset(t_all_var *all, t_command *command)
{
	t_env	*iterator;
	char	*tmp;
	int		exit_code;
	int		i;

	i = 0;
	exit_code = 0;
	while (command->argv[++i])
	{
		if (not_valid_identifier(all, "unset", command->argv[i], &exit_code))
			continue ;
		iterator = all->exp;
		while (iterator)
		{
			if (!ft_strcmp(iterator->variable, command->argv[i]))
			{
				tmp = ft_strdup(iterator->variable);
				iterator = iterator->next;
				unset(all, tmp, NULL, NULL);
			}
			else
				iterator = iterator->next;
		}
	}
	return (exit_code);
}
