/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sintax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquenten <rquenten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:11:22 by rquenten          #+#    #+#             */
/*   Updated: 2021/05/31 12:11:22 by rquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

/*
** _________________________________________________________________SUBFUNCTIONS
*/

static void	set_flags(char ch, int *f)
{
	if (f[SLASH] == 2)
		f[SLASH] = 0;
	if (!f[SLASH] && ch == f[MARK])
		f[MARK] = 0;
	else if (!f[MARK] && !f[SLASH] && (ch == '\'' || ch == '\"'))
		f[MARK] = ch;
	else if (f[SLASH])
		f[SLASH] = 2;
	else if (f[MARK] != '\'' && !f[SLASH] && ch == '\\')
		f[SLASH] = 1;
	else if (!f[MARK] && !f[SLASH] && f[SEPARATOR]
		&& (ch == '|' || ch == ';'))
		f[SEPARATOR] = -1;
	else if (!f[MARK] && !f[SLASH] && (ch == '|' || ch == ';'))
		f[SEPARATOR] = ch;
}

// 																			   |
// ----------------------------------------------------------------------------|
// 																			   |

static int	incomplete_redirect(char *str, size_t i, int *f)
{
	if (f[MARK] || f[SLASH] || !compare_char_with("<>", str[i]))
		return (0);
	i += 1 + (str[i + 1] == '>' && str[i] != '<');
	if (!str[i])
		return (1);
	i = skip_spaces(str, i);
	if (str[i] && !compare_char_with("<>|;", str[i]))
		return (0);
	return (1);
}

/*
** ________________________________________________________________MAIN FUNCTION
*/

int	validate_sintax(char *str)
{
	int		f[COUNT_FLAGS];
	size_t	i;

	i = 0;
	f[MARK] = 0;
	f[SLASH] = 0;
	f[SEPARATOR] = ';';
	while (str[i])
	{
		if (!f[MARK] && !f[SLASH])
			i = skip_spaces(str, i);
		if (str[i] != ';' && str[i] != '|' && str[i])
			f[SEPARATOR] = 0;
		set_flags(str[i], f);
		if (f[SEPARATOR] < 0 || incomplete_redirect(str, i, f))
			return (0);
		i += !!str[i];
	}
	if (f[MARK] || f[SLASH] == 1 || f[SEPARATOR] == '|')
		return (0);
	return (1);
}
