/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:34:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/31 21:20:40 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <semaphore.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

// ______________________________________________________________________STRUCTS

enum e_programs_names
{
	IS_DEATH,
	WRITE_SEM,
	HAVE_EATEN,
	TRAY_FOR_FORKS,
	COUNT_NAMES,
};

typedef struct s_chair
{
	int				seat_number;
	int				count;
	void			*v;
	pthread_t		philo;
	sem_t			*forks_tray;
	void			*left_chair;
	void			*right_chair;
}				t_chair;

typedef struct s_v
{
	char			**names;
	t_chair			*table;
	size_t			count_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				each_must_eat;
	size_t			count_philo_ready;
	size_t			start_time;
	int				error;
	int				finish;
	sem_t			**program_sem;
}				t_v;

// ________________________________________________________CHECKING INPUT VALUES

int		checking_input_values(int argc, char *argv[]);

// _______________________________________________________________________ERRORS

long	errorka_0(char *error_message, int ret_value);
long	errorka_1(char *what_wrong, char *variable, char *value);
void	errorka_2(t_v *v, int seat_number);
void	finish(t_v *v);

// _________________________________________________________________________INIT

t_v		*init(int argc, char *argv[]);

// ________________________________________________________________INVITE GUESTS

int		invite_guests_to_the_table(t_v *v);

// ________________________________________________________________________UTILS

void	ft_putnbr(size_t n, int fd);
size_t	ft_strlen(const char *s);
size_t	get_time(void);
void	logs(t_v *v, int seat_number, char *movement);
int		sini(char *str_with_number);

// ___________________________________________________________________WAIT PHILO

int		wait_philosophers(t_v *v);

#endif