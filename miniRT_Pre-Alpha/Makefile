# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 01:13:16 by lignigno          #+#    #+#              #
#    Updated: 2021/03/13 13:41:14 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY :	all clean fclean re bonus \
			clean_for_fclean \
			other_compils

# _____________________________________________________________________VARIABLES

GREEN_COL := \033[38;2;0;145;15
YELLOW_COL := \033[1;38;2;204;194;0

NAME := miniRT

SRC :=	minirt.c \
		utils_1.c \
		slider.c \
		cleaner.c \
		free_bckg_imgs.c \
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
		get_triangle.c \
		main_render.c \
		render_cameras_views.c \
		ray_trace.c \
		functions_for_vectors_1.c \
		functions_for_vectors_2.c \
		setup_cams_views.c \
		inters_with_sphere.c \
		shadow_ray.c \
		normal_for_object.c \
		inters_with_plane.c \
		create_bmp_img.c \
		inters_with_square.c \
		inters_with_triangle.c \
		inters_with_cylinder.c

OBJ := $(addprefix obj/, $(SRC:.c=.o))

HEADERS := libft/libft.h libft/gnl/gnl.h project_header.h

LIBS := libft/libft.a \
		minilibx/libmlx.a \
		libmlx.dylib

FLAGS := -O3 -Wall -Wextra -Werror

FRAMEWORKS := -framework OpenGL -framework AppKit

export FLAGS
export GREEN_COL

# _______________________________________________________________________TARGETS

all : $(NAME)

$(NAME) : obj/ other_compils $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LIBS) $(FRAMEWORKS) -o $(NAME)
	@echo "$(GREEN_COL)m"
	@echo "   /---------------------\\"
	@echo "   | everything is ready |"
	@echo "   \\---------------------/\n"
	@echo ""
	@echo "    $(YELLOW_COL)mENTER IN THE TERMINAL$(GREEN_COL);1m"
	@echo "    ∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨\n"
	@echo "./miniRT _scenes/scene_name.rt\n"

#
obj/%.o : %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

obj/ :
	@mkdir obj/

other_compils :
	@make -C minilibx/
	@make -C minilibx_d/
	@make -C libft/
	@make -C parser_and_processing/
	@make -C rendering/
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
	@echo "$(YELLOW_COL);4;1mobject\033[0m$(YELLOW_COL);1m files for $(YELLOW_COL);4;1m$(NAME)\033[0m$(YELLOW_COL);1m have been deleted\033[0m"

fclean : clean_for_fclean
	@rm -rf $(NAME)
	@make clean -C minilibx/
	@make clean -C minilibx_d/
	@make fclean -C libft/
	@echo "$(YELLOW_COL);4;1m$(NAME)\033[0m$(YELLOW_COL);1m have been deleted\033[0m"

re : fclean all

bonus : all