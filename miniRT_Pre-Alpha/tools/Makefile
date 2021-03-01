# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/01/21 13:23:15 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC := slider.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

FLAGS := -Wall -Wextra -Werror

#$(FLAGS)
all : $(OBJ)

../obj/%.o : %.c ../project_header.h
	gcc -c $< -o $@