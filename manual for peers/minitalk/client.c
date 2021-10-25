/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 23:30:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/05 21:42:10 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//                            ЛУЧШЕ НАЧАТЬ С README

/*
	ОБОЗНАЧЕНИЯ define И ПРИСТАВОК :
		НАПРАВЛЕНИЯ :
			LR - отправка битов/символов слева направо;
			RL - отправка битов/символов справа налево;
		ПРИНАДЛЕЖНОСТИ :
			B - для работы с битами в символе;
			C - для работы с символами в строке;

	ИНСТРУКЦИЯ ПО ВНЕДРЕНИЮ В СВОЙ КОД :
		    Направление должно совпадать по принадлежности. То есть, функции
		с одинаковой принадлежнастью должны иметь одинаковые направления,
		иначе поведение не определено, это нужно учесть при интеграции
		в свой код. По этому для удобства я сделал два define
		C_direction и B_direction для каждой принадлежности в отдельности.
		Функции с одной принадлежностью (C или B) должны работать в одну сторону.
*/

// _________________________________________________________________SUBFUNCTIONS

static int	C_set_iterator(int len)
{
	if (C_direction_sending == LR)
		return (0 * len);
	else
		return (len - 1);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static int	C_condition(int iterator, int len)
{
	if (C_direction_sending == LR)
		return(iterator < len);
	else
		return(len - iterator > -1);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static char	C_get_char(const char *str, int len, int iterator)
{
	if (C_direction_sending == LR)
		return (str[iterator]);
	else
		return (str[len - iterator]);

}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

// для красивого вывода
static void	write_curent_state(char ch, int i, int flag, int size_char)
{
	fprintf(stderr, "\r");
	print_bits(ch, i + flag, 0 - flag, CLIENT_COLOR, size_char);
	if (flag == 1 && B_direction_sending == LR)
		fprintf(stderr, "   <<");
	else if (flag == 1)
		fprintf(stderr, "   >>");
	else if (flag > 1)
		fprintf(stderr, "     ");
	else
		fprintf(stderr, " push");
	usleep(1000000 / FPS * (flag < 2));
}

static void	B_sending_char(char ch, int size_char)
{
	char	signal;
	int		i;

	i = 0;
	while (i < size_char * 8)
	{
		// получаем бит.
		if (B_direction_sending == LR)
			signal = (ch & 0x80 * size_char) >> (size_char * 8 - 1);
		else
			signal = (ch & 0x1);
		write_curent_state(ch, i, 0, size_char);
		// заменить данную строку на отправку [ signal ] куда нужно.
		printf("%c", signal + '0');
		// смещаем биты.
		if (B_direction_sending == LR)
			ch <<= 1;
		else
			ch >>= 1;
		write_curent_state(ch, i, 1, size_char);
		i++;
	}
	write_curent_state(ch, i, 2, size_char);
}

// _________________________________________________________________MAIN FUNTION
/*
	    Написал уточнения и несколько функции чтобы можно было подобрать
	для себя отправку котроя будет более понятна.
	    Направление может меняться в "header.h".
*/

int	main(int argc, char const *argv[])
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		ch;

	(void)argc;
	i = 1;
	while(argv[i])
	{
		len = ft_strlen_end_char(argv[i], END_CHARACTER);
		j = C_set_iterator(len);
		while (C_condition(j, len))
		{
			// не стал писать
			// BLR_sending_char(CLR_get_char(argv, len, j));
			// так как менее читаемо.

			// получение буквы.
			ch = C_get_char(argv[i], len, j);
			// отправка битов символа.
			// также можно передать размерность одного символа
			B_sending_char(ch, sizeof(ch));
			j++;
		}
		i++;
	}
	//     Отправка символа END_CHARACTER что-бы сказать что отправка закончена.
	// Это действие произвожу здесь, так как отправлять слово можно не только
	// в направлении LR (тогда просто можно было в цикле проходить на один
	// символ больше цепляя END_CHARACTER), но и RL. То есть отправка
	// END_CHARACTER после цикла в благодаря которому отправляем все символы
	// строки (кроме END_CHARACTER) более универсальна в плане алгоритма, так
	// как не зависит от порядка отправки символов.
	//     Так же у нас в передаваемой строке не может быть символа
	// END_CHARACTER в середине, так как чтение прервётся на этом символе.
	B_sending_char(END_CHARACTER, sizeof(char));
	return (0);
}
