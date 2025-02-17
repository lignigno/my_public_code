/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd_and_oldpwd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 09:52:02 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// ________________________________________________________________MAIN FUNCTION
// ___________________________________________________________________CHANGE PWD

void	change_pwd(t_all_var *all)
{
	t_env	*env;
	int		i;

	i = 0;
	while (i < 2)
	{
		if (i < 1)
			env = all->exp;
		else
			env = all->env;
		env = get_variable(env, "PWD");
		if (!env)
			add_var(all, "PWD", getcwd(NULL, 0));
		else if (!env->value)
			env->value = getcwd(NULL, 0);
		else
		{
			free(env->value);
			env->value = getcwd(NULL, 0);
		}
		i++;
	}
}

// _________________________________________________________________SUBFUNCTIONS
// ________________________________________________________________CHANGE OLDPWD

static char	*for_free(t_all_var *all, char *need_dup)
{
	char	*result;

	if (!need_dup)
		return (NULL);
	result = ft_strdup(need_dup);
	if (!result)
		errorka(all, NMA_ENV);
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static void	ubrat_oldpwd(t_all_var *all)
{
	char	*tmp;

	tmp = ft_strdup("OLDPWD");
	if (!tmp)
		errorka(all, NMA_ENV);
	unset(all, tmp, NULL, NULL);
}

// ________________________________________________________________MAIN FUNCTION

void	change_oldpwd(t_all_var *all, char *tmp)
{
	t_env	*env;
	int		i;

	if (get_variable(all->env, "OLDPWD") && !tmp)
		ubrat_oldpwd(all);
	i = -1;
	while (++i < 2)
	{
		if (i < 1)
			env = all->exp;
		else
			env = all->env;
		env = get_variable(env, "OLDPWD");
		if ((!env && i && tmp) || (!env && !i))
			add_var(all, "OLDPWD", for_free(all, tmp));
		else if (env && !env->value)
			env->value = for_free(all, tmp);
		else if (env && ((i && tmp) || (!i)))
		{
			free(env->value);
			env->value = for_free(all, tmp);
		}
	}
	if (tmp)
		free(tmp);
}
