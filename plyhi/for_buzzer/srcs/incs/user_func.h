/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 04:54:21 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/02 10:46:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_FUNC_H
#define USER_FUNC_H

#include "buzzer.h"

// BASE OCTAVE

/*
 * any other octave can be obtained by the formula
 * note * 2 in degree (octave number)
 * octave number [0 ; 9]
 * 
 * example :
 *     G_ * (1 << 0)
 *     F * (1 << 3)
*/

#define C	16.3516015625
#define C_	17.32390625
#define D	18.35404296875
#define D_	19.4454296875
#define E	20.60171875
#define F	21.8267578125
#define F_	23.1246484375
#define G	24.49970703125
#define G_	25.95654296875
#define	A	27.5
#define	A_	29.135234375
#define B	30.86771484375

#endif