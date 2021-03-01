# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/01/31 01:04:22 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC :=	processing_input_values.c \
		parser_scene_file.c \
		utils_for_parser_1.c \
		utils_for_parser_2.c \
		get_resolution.c \
		get_ambient.c \
		get_camera.c \
		get_light.c \
		get_plane.c \
		get_sphere.c \
		get_square.c \
		get_cylinder.c \
		get_triangle.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

FLAGS := -Wall -Wextra -Werror

#$(FLAGS)
all : $(OBJ)

../obj/%.o : %.c ../project_header.h
	gcc -c $< -o $@