# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 01:13:16 by lignigno          #+#    #+#              #
#    Updated: 2021/02/09 08:54:46 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY :	all clean fclean re bonus \
			clean_for_fclean \
			other_compils

# _____________________________________________________________________VARIABLES

NAME := miniRT

SRC :=	minirt.c \
		utils_1.c \
		slider.c \
		cleaner.c \
		free_imgs.c \
		free_cam.c \
		free_light.c \
		free_plane.c \
		free_sphere.c \
		free_square.c \
		free_cylinder.c \
		free_triangle.c \
		other_easy_free.c \
		errorka.c \
		initial_setup.c \
		setup_canvas.c \
		setup_top_p.c \
		setup_crt_p.c \
		setup_adj_p.c \
		setup_objects.c \
		unsorted_functions.c \
		processing_input_values.c \
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

OBJ := $(addprefix obj/, $(SRC:.c=.o))

HEADERS := libft/libft.h libft/gnl/gnl.h project_header.h

LIBS := libft/libft.a \
		minilibx/libmlx.a \
		libmlx.dylib

FLAGS := -Wall -Wextra -Werror

FRAMEWORKS := -framework OpenGL -framework AppKit

# _______________________________________________________________________TARGETS

all : $(NAME)

#$(FLAGS)
$(NAME) : obj/ other_compils $(OBJ)
	@gcc $(OBJ) $(LIBS) $(FRAMEWORKS) -o $(NAME)
	@echo "\033[32;1m"
	@echo "/---------------------\\"
	@echo "| everything is ready |"
	@echo "\\---------------------/\n"
#@say everything is ready

#-Imlx
obj/%.o : %.c $(HEADERS)
	gcc -c $< -o $@

obj/ :
	@mkdir obj/

other_compils :
	@make -C minilibx/
	@make -C minilibx_d/
	@make -C libft/
	@make -C parser_and_processing/
	@make -C tools/
	@make -C cleaner/
	@make -C initial_setups/

# ________________________________________________________________CLEANS TARGETS

clean :
	@rm -rf obj/
	@make clean -C minilibx/
	@make clean -C minilibx_d/
	@make clean -C libft/
	@echo "\033[33;1mobject files for $(NAME) have been deleted\033[0m"

# this clean does not clean the object files after
# the makefiles of the libraries have done so
clean_for_fclean :
	@rm -rf obj/
	@echo "\033[33;4;1mobject\033[0;33;1m files for \033[33;4;1m$(NAME)\033[0;33;1m have been deleted\033[0m"

fclean : clean_for_fclean
	@rm -rf $(NAME)
	@make clean -C minilibx/
	@make clean -C minilibx_d/
	@make fclean -C libft/
	@echo "\033[33;4;1m$(NAME)\033[0;33;1m have been deleted\033[0m"

re : fclean all

bonus : all