/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_ch_with.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:12:09 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:12:09 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	compare_char_with(const char *arr_type, char ch)
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
