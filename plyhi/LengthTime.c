/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LengthTime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 05:20:48 by lignigno          #+#    #+#             */
/*   Updated: 2021/11/14 08:26:11 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// START______________________________________________________________CODE BLOCK

#include <sys/time.h>
#include <stdio.h>

#define USEC_10_0 0x0 // result in microseconds
#define USEC_10_1 0x1
#define USEC_10_2 0x2
#define USEC_10_3 0x3 // result in miliseconds
#define USEC_10_4 0x4 // result in centiseconds
#define USEC_10_5 0x5 // result in deciseconds
#define USEC_10_6 0x6 // result in seconds

//                                                                             |
// ____________________________________________________________________________|
//                                                                             |

size_t	LengthTime(void	(*testFunc)(size_t), size_t scale, char outTime)
{
	size_t			result;
	struct timeval	start_time;
	struct timeval	finish_time;
	size_t			divider;

	divider = 1;
	for (size_t i = 0; i < outTime; i++)
		divider *= 10;

	gettimeofday(&start_time, NULL);
	testFunc(scale);
	gettimeofday(&finish_time, NULL);

	result = (size_t)finish_time.tv_sec * 1000000 + finish_time.tv_usec;
	result -= (size_t)start_time.tv_sec * 1000000 + start_time.tv_usec;
	return (result / divider);
}

//                                                                             |
// ____________________________________________________________________________|
//                                                                             |

size_t	LengthTimeWhile(void (*testFunc)(void), size_t scale, char outTime)
{
	size_t			i;
	size_t			result;
	struct timeval	start_time;
	struct timeval	finish_time;
	size_t			divider;

	divider = 1;
	
	i = -1;
	while (++i < outTime)
		divider *= 10;

	i = -1;
	gettimeofday(&start_time, NULL);
	while (++i < scale)
		testFunc();
	gettimeofday(&finish_time, NULL);

	result = (size_t)finish_time.tv_sec * 1000000 + finish_time.tv_usec;
	result -= (size_t)start_time.tv_sec * 1000000 + start_time.tv_usec;
	return (result / divider);
}

// END________________________________________________________________CODE BLOCK

/*
** [USAGE EXAMPLE]      [USAGE EXAMPLE]     [USAGE EXAMPLE]      [USAGE EXAMPLE]
*/

// _________________________________________________________________SUBFUNCTIONS

/*
**     These functions were written mainly
** to check which of the algorithms will be faster.
** 
** alg_1 vs alg_2
** 
**     This means that it will not be possible
** to measure the operating time of the WORK_BLOCK
** 
** How to choose which function is better to use:
** -----------------------------------------------------------------------------
**     When the difference is only in the algorithm of the function itself
** 
** ft_putnbr_alg_1(134565);
** ft_putnbr_alg_2(134565);
** 
** USE [ LengthTimeWhile ]
** -----------------------------------------------------------------------------
**     When, in addition to the algorithm itself, initialization also differs
** 
** print_msg_v1("message");
** print_msg_v2("message", other_params_for_optimization);
** 
** USE [ LengthTime ]
** 
** BUT!!!
**     You will need to add WHILE or FOR to WORK_BLOCK,
** which will call your function SCALE times
** -----------------------------------------------------------------------------
*/

// EXAMPLE TEST_FUNC

/*
void	func_test_speed()
{

	// START____INIT_BLOCK

	super_puper_struct	all_var;

	very_slow_init_for_somebodyFunc(&all_var);

	// END______INIT_BLOCK




	// START____WORK_BLOCK

	// for (size_t i = 0; i < scale; i++) if need
	somebodyFunc(all_var);

	// END______WORK_BLOCK

}
*/

/*
**     Maybe I'll decide later to add new buns
** for such measurements in time (and add a normal manual for them)
** 
** :)
*/