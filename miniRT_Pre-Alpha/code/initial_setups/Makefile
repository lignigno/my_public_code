# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/03/13 10:57:56 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC :=	initial_setup.c \
		setup_canvas.c \
		setup_top_p.c \
		setup_crt_p.c \
		setup_adj_p.c \
		setup_objects.c \
		setup_cams_views.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

all : $(OBJ)
	@echo "$(GREEN_COL)minitial_setups ready\033[0m"

../obj/%.o : %.c ../project_header.h
	gcc $(FLAGS) -c $< -o $@