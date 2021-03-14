# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/03/13 10:48:13 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC := 	gnl.c \
		gnl_utils.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

all : $(OBJ)

../obj/%.o : %.c ../libft.h gnl.h
	gcc $(LIB_FLAGS) -c $< -o $@