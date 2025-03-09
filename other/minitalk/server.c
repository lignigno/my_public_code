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

static char	B_get_signal()
{
	char	signal;
	int		readed;

	readed = read(0, &signal, 1);
	if (readed < 0)
		exit(printf("read broke down"));
	signal = signal == '1';
	return (signal);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

// для красивого вывода
static void	write_curent_state(char ch, int i, int flag, int size_char)
{
	fprintf(stderr, "\r");
	print_bits(ch, i + flag, size_char * 8 + flag - 1, SERVER_COLOR, size_char);
	if (flag == 1 && B_direction_sending == LR)
		fprintf(stderr, "  <<");
	else if (flag == 1)
		fprintf(stderr, "  >>");
	else if (flag > 1)
		fprintf(stderr, "    ");
	else
		fprintf(stderr, " add");
	usleep(1000000 / FPS * (flag < 2));
}

static char	B_get_char(int size_char)
{
	char	signal;
	char	ch;
	int		i;

	i = 0;
	ch = '\0';
	while (i < size_char * 8)
	{
		// получаем сигнал.
		signal = B_get_signal();
		// смещаем биты.
		if (B_direction_sending == LR)
			ch <<= 1;
		else
			ch >>= 1;
		write_curent_state(ch, i, 1, size_char);
		// добавляем бит.
		if (B_direction_sending == LR)
			ch |= signal;
		else
			ch |= signal << (size_char * 8 - 1);
		i++;
		write_curent_state(ch, i, 0, size_char);
	}
	write_curent_state(ch, -2, 2, size_char);
	printf("\n");
	return (ch);
}

// _________________________________________________________________MAIN FUNTION
/*
	    Написал уточнения и несколько функции чтобы можно было подобрать
	для себя приём котрый будет более понятен.
	    Направление может меняться в "header.h".
*/

int	main(void)
{
	char	ch;
	char	*result;

	result = malloc(sizeof(ch));
	if (!result)
		exit(printf("malloc broke down"));
	*result = '\0';
	while(1)
	{
		// получение символа.
		ch = B_get_char(sizeof(ch));
		if (ch == END_CHARACTER)
			break ;
		// моя функция добавления символа в строку;
		if (C_direction_sending == LR)
			result = add_char(result, ch, -1);
		else
			result = add_char(result, ch, 0);
		if (!result)
			exit(printf("malloc broke down"));
	}
	printf("The resulting string : {%s}\n", result);
	return (0);
}
