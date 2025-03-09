/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:52:23 by lignigno          #+#    #+#             */
/*   Updated: 2021/05/31 17:28:10 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// _________________________________________________________________SUBFUNCTIONS

static char	**init_this(t_all_var *all, t_env *env, int *count)
{
	char	**result;
	int		i;

	*count = 0;
	while (env)
	{
		(*count)++;
		env = env->next;
	}
	result = malloc((*count) * sizeof(char *) + 1);
	if (!result)
		errorka(all, NMA_CONVERT);
	i = 0;
	while (i <= (*count))
		result[i++] = NULL;
	return (result);
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static char	**convert(t_all_var *all, t_env *env)
{
	char	**result;
	char	*old_adr;
	int		count;
	int		i;

	result = init_this(all, env, &count);
	i = 0;
	while (i < count)
	{
		result[i] = ft_strdup(env->variable);
		if (!result)
			errorka(all, NMA_EXECUTE);
		result[i] = add_char(result[i], '=', -1);
		if (!result)
			errorka(all, NMA_EXECUTE);
		old_adr = result[i];
		result[i] = ft_strjoin(result[i], env->value);
		free(old_adr);
		env = env->next;
		i++;
	}
	return (result);
}

// ________________________________________________________________MAIN FUNCTION

void	call_other(t_all_var *all, t_command *command, char *full_name)
{
	execve(full_name, command->argv, convert(all, all->env));
	minishell_errorka("command not found", command->argv[0]);
	exit(127);
}
