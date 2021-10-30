/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:49:48 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/28 08:35:41 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	USER_FUNC_H
#define USER_FUNC_H

#include "LED.h"

#define TMP_STRIPLEN 10
#define TMP_STRIPLEN_BIT 241

color_t	EvenOdd(u16_t num);
color_t	RainbowPos(u16_t num);
color_t	RainbowCall(u16_t not_use);
color_t	GradientSlider(u16_t slider);

#endif
