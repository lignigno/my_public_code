/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buzzer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 07:47:41 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/02 10:47:06 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUZZER_H
#define BUZZER_H

// _____________________________________________________________________INCLUDES

#include <stdio.h>

// ______________________________________________________________________DEFINES

#define MC_Hz 32000000

typedef u_int8_t	u8_t;	// unsigned 8-bit type
typedef u_int16_t	u16_t;	// unsigned 16-bit type
typedef u_int32_t	u32_t;	// unsigned 32-bit type
typedef u_int64_t	u64_t;	// unsigned 64-bit type

#define LEN_SINGNAL 1

u16_t	singleSignal[LEN_SINGNAL];

#endif