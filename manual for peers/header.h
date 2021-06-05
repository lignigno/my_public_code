/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 03:47:58 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/05 21:36:20 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define LR 1
# define RL 0

// НАСТРОЙКИ

# define FPS 10
# define CLIENT_COLOR "\033[38;2;35;73;222;1m"
# define SERVER_COLOR "\033[38;2;194;23;83;1m"
# define CHANGE "\033[38;2;0;145;15;1m"
# define OFFSET "\033[38;2;194;194;0;1m"
# define END_CHARACTER '\0'
# define C_direction_sending LR
# define B_direction_sending LR

size_t	ft_strlen_end_char(const char *str, char end_char);
char	*add_char(char *str, char ch, size_t index);
void	print_bits(char ch, int change, int offset, char *color, int size_char);

#endif
