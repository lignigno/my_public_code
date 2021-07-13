# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:11:24 by lignigno          #+#    #+#              #
#    Updated: 2021/07/13 03:20:52 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re check_obj_dir

# _____________________________________________________________________VARIABLES

COL_0			:=	\033[38;2;0;145;15
COL_1			:=	\033[38;2;46;84;240
COL_2			:=	\033[37
UNSET			:=	\033[m

NAME			:=	philo_three

SRC_DIR			:=	srcs
WRITE			:=	../scripts/bp.sh
OBJ_DIR			:=	../obj/$(NAME)
FLAGS			:=	-O3 -Wall -Wextra -Werror
INCLUDE			:=	$(SRC_DIR)/headers/
VPATH			:=	$(shell find $(SRC_DIR) -type d)

SRC				:=	$(wildcard $(addsuffix /*.c, $(VPATH)))
OBJ				:=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
DEP				:=	$(wildcard $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.d))))

# _______________________________________________________________________TARGETS

all				:	$(OBJ_DIR) $(NAME)

$(NAME)			:	$(OBJ)
					@gcc $(OBJ) -o $@
					@echo
					@printf "\t\t"
					@bash $(WRITE) "COMMAND + V" "0.08" "$(COL_2);3;1m" "$(COL_0);3m"
					@echo "\n"
					@printf "$(shell pwd)/$@ 200 302 100 200" | pbcopy

$(OBJ_DIR)/%.o	:	%.c
					gcc $(FLAGS) -I $(INCLUDE) -MD -c $< -o $@

$(OBJ_DIR)		:
					@mkdir -p $(OBJ_DIR)/

include $(DEP)

# ________________________________________________________________CLEANS TARGETS

clean			:
					@rm -rf $(OBJ_DIR)
					@echo "$(COL_1);3;1mobject\033[23;22m files for \033[3;1m$(NAME)\033[23;22m have been deleted\033[0m"

check_obj_dir	:
					@if [ -d $(dir $(OBJ_DIR)) ] && [ -z "$(shell ls -A $(dir $(OBJ_DIR)) 2>stderr)" ]; then rm -rf $(dir $(OBJ_DIR)) ; fi
					@rm -f stderr

fclean			:	clean check_obj_dir
					@rm -f $(NAME)
					@echo "$(COL_1);3;1m$(NAME)\033[23;22m have been deleted\033[0m"

re				:	fclean all