#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_eating.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 02:02:59 by lignigno          #+#    #+#              #
#    Updated: 2021/06/16 02:02:59 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUTPUT_FILE="test_eating.txt"
PATH_TO_PHILO_DIR=$(pwd)/
R="\033[1;38;2;176;5;25m"
G="\033[1;38;2;50;150;20m"
UN="\033[m"

# __________________________________________________________________SUBFUNCTIONS

check_input_args()
{
	if [ $1 -lt $2 ];
	then
		echo -e "$R$3$UN"
		exit
	fi
}

#                                                                              |
# -----------------------------------------------------------------------------|
#                                                                              |

file_exist()
{
	if ! [ -e $1 ];
	then
		echo -e "${R}Not found '$1'$UN"
		exit
	fi
}

#                                                                              |
# -----------------------------------------------------------------------------|
#                                                                              |

is_directory()
{
	if ! [ -d $1 ];
	then
		echo -e "$R$1 not directory$UN"
		exit
	fi
}

#                                                                              |
# -----------------------------------------------------------------------------|
#                                                                              |

try_make()
{
	make -C $1/
	if [ $? -ne 0 ];
	then
		echo -e "\n${R}I can't make$UN"
		exit
	fi
}

# ____________________________________________________________________MAIN LOGIC

check_input_args "$#" 1 "Need {number_of_philosophers}!"
check_input_args "$#" 2 "Need {time_to_die}!"
check_input_args "$#" 3 "Need {time_to_eat}!"
check_input_args "$#" 4 "Need {time_to_sleep}!"
check_input_args "$#" 5 "Need {number_of_times_each_philosopher_must_eat}!"
check_input_args "$#" 6 "Need {WHAT_PHILO}!"

WHAT_PHILO=$6
file_exist $PATH_TO_PHILO_DIR/$WHAT_PHILO
is_directory $PATH_TO_PHILO_DIR/$WHAT_PHILO
try_make $PATH_TO_PHILO_DIR/$WHAT_PHILO
file_exist $PATH_TO_PHILO_DIR/$WHAT_PHILO/$WHAT_PHILO

# launch programm
echo $WHAT_PHILO/$WHAT_PHILO $1 $2 $3 $4 $5
$WHAT_PHILO/$WHAT_PHILO $1 $2 $3 $4 $5 > $OUTPUT_FILE

if [ $? -ne 0 ];
then
	exit
fi

# check output values
for (( i=1; $i<=$1; i=$(($i+1)) ))
do
	printf "philo %3i eating" $i
	COUNT=$(cat $OUTPUT_FILE | grep " $i is eating" | wc -l)
	if [ $COUNT -ge $5 ];
	then
		echo -e "$G$COUNT$UN"
	else
		echo -e "$R$COUNT$UN"
	fi
done
