# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 05:39:35 by lignigno          #+#    #+#              #
#    Updated: 2021/03/13 10:52:00 by lignigno         ###   ########.fr        #
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

all : $(OBJ)
	@echo "$(GREEN_COL)mparser_and_processing ready\033[0m"

../obj/%.o : %.c ../project_header.h
	gcc $(FLAGS) -c $< -o $@