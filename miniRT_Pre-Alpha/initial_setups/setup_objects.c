/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 02:29:28 by lignigno          #+#    #+#             */
/*   Updated: 2021/01/31 02:31:10 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

void			setup_objects(t_vars *vars)
{
	vars->objects.cam = NULL;
	vars->objects.light = NULL;
	vars->objects.plane = NULL;
	vars->objects.sphere = NULL;
	vars->objects.square = NULL;
	vars->objects.cylinder = NULL;
	vars->objects.triangle = NULL;
}
