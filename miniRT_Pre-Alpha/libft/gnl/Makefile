# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/01/21 05:38:54 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC := 	gnl.c \
		gnl_utils.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

FLAGS := -I. -Wall -Wextra -Werror

all : $(OBJ)

../obj/%.o : %.c ../libft.h gnl.h
	gcc $(FLAGS) -c $< -o $@