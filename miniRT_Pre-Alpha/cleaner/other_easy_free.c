/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_easy_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:23:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/29 14:24:07 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

void	free_mlx(t_vars *vars)
{
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
}
