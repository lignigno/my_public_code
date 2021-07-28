/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:12:23 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/28 17:54:10 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

// ______________________________________________________________________STRUCTS

typedef struct s_chair
{
	int				seat_number;
	int				count;
	void			*v;
	pthread_t		philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	void			*left_chair;
	void			*right_chair;
	size_t			start_time;
}				t_chair;

typedef struct s_v
{
	t_chair			*table;
	size_t			count_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				each_must_eat;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	have_eaten;
	size_t			start_time;
	int				error;
}				t_v;

// ________________________________________________________CHECKING INPUT VALUES

int		checking_input_values(int argc, char *argv[]);

// _______________________________________________________________________ERRORS

long	errorka_0(char *error_message, int ret_value);
long	errorka_1(char *what_wrong, char *variable, char *value);
void	errorka_2(t_v *v, t_chair *place);
int		finish(t_v *v);

// _________________________________________________________________________INIT

t_v		*init(int argc, char *argv[]);

// ________________________________________________________________INVITE GUESTS

int		invite_guests_to_the_table(t_v *v);

// ________________________________________________________________________UTILS

void	ft_putnbr(size_t n, int fd);
size_t	ft_strlen(const char *s);
size_t	get_time(void);
void	logs(t_v *v, t_chair *place, char *movement);
int		sini(char *str_with_number);

#endif