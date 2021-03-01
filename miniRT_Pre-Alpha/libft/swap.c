/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 23:58:48 by lignigno          #+#    #+#             */
/*   Updated: 2020/12/20 12:09:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			swap_ch(char *var_1, char *var_2)
{
	char		tmp;

	tmp = *var_1;
	*var_1 = *var_2;
	*var_2 = tmp;
}

void			swap_ll(long long *var_1, long long *var_2)
{
	long long	tmp;

	tmp = *var_1;
	*var_1 = *var_2;
	*var_2 = tmp;
}
