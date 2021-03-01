/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:30 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/29 13:04:28 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

static void	clear_only(t_vars *vars)
{
	int		who_to_cleared;

	who_to_cleared = vars->need_cleared[CLEAR_ONLY];
	vars->cleared_func[who_to_cleared](vars);
	vars->need_cleared[CLEAR_ONLY] = 0;
}

/*
** printf("need_cleared[%i] : %i\n", i, vars->need_cleared[i]);
*/

static void clear_all(t_vars *vars)
{
	int		i;

	i = 1;
	while (i < 21)
	{
		if (vars->need_cleared[i])
			vars->cleared_func[i](vars);
		i++;
	}
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

void		cleaner(t_vars *vars)
{
	if (vars->need_cleared[CLEAR_ONLY])
	{
		clear_only(vars);
		return ;
	}
	clear_all(vars);
}
