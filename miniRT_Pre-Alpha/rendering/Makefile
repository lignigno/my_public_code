# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 14:13:57 by lignigno          #+#    #+#              #
#    Updated: 2021/02/26 13:39:07 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

SRC :=	main_render.c \
		render_cameras_views.c \
		ray_trace.c \
		functions_for_vectors_1.c \
		functions_for_vectors_2.c \
		inters_with_sphere.c \
		shadow_ray.c \
		normal_for_object.c \
		inters_with_plane.c \
		inters_with_square.c \
		inters_with_triangle.c \
		inters_with_cylinder.c

OBJ := $(addprefix ../obj/, $(SRC:.c=.o))

FLAGS := -Wall -Wextra -Werror

#$(FLAGS)
all : $(OBJ)

../obj/%.o : %.c ../project_header.h
	gcc -g3 $(FLAGS) -c $< -o $@
