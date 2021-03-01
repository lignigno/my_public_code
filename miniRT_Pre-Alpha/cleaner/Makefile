# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/01/31 01:08:13 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC := 	cleaner.c \
		free_imgs.c \
		free_cam.c \
		free_light.c \
		free_plane.c \
		free_sphere.c \
		free_square.c \
		free_cylinder.c \
		free_triangle.c \
		other_easy_free.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

FLAGS := -Wall -Wextra -Werror

#$(FLAGS)
all : $(OBJ)

../obj/%.o : %.c ../project_header.h
	gcc -c $< -o $@