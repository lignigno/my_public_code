# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/01/21 13:21:59 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC :=	initial_setup.c \
		setup_canvas.c \
		setup_top_p.c \
		setup_crt_p.c \
		setup_adj_p.c \
		setup_objects.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

FLAGS := -Wall -Wextra -Werror

#$(FLAGS)
all : $(OBJ)

../obj/%.o : %.c ../project_header.h
	gcc -c $< -o $@