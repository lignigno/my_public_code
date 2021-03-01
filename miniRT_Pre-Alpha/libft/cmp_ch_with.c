/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_ch_with.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:10:27 by lignigno          #+#    #+#             */
/*   Updated: 2020/12/20 12:09:21 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		compare_char_with(const char *arr_type, char ch)
{
	int		i;

	i = 0;
	while (arr_type[i] != '\0')
	{
		if (arr_type[i] == ch)
			return (arr_type[i]);
		i++;
	}
	return ('\0');
}
