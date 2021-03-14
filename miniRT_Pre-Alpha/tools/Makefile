# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/03/13 10:51:10 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC := slider.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

all : $(OBJ)
	@echo "$(GREEN_COL)mtools ready\033[0m"

../obj/%.o : %.c ../project_header.h
	gcc $(FLAGS) -c $< -o $@