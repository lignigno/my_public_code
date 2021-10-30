# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:11:24 by lignigno          #+#    #+#              #
#    Updated: 2021/10/29 07:47:08 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re check_obj_dir

# _____________________________________________________________________VARIABLES

COL_0					:=	\033[38;2;0;145;15
COL_1					:=	\033[38;2;46;84;240
COL_2					:=	\033[37
UNSET					:=	\033[m

NAME					:=	buzzer_example

SRC_DIR					:=	srcs
OBJ_DIR					:=	obj
FLAGS					:=	-O2 -Wall -Wextra -Werror
INCLUDE					:=	$(SRC_DIR)/incs
VPATH					:=	$(shell find $(SRC_DIR) -type d)

SRC						:=	$(wildcard $(addsuffix /*.c, $(VPATH)))
OBJ						:=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
DEP						:=	$(wildcard $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.d))))

# _______________________________________________________________________TARGETS

all						:	$(OBJ_DIR) $(NAME)

$(NAME)					:	$(OBJ)
							@gcc $(OBJ) -o $@
							@echo
							@printf "\t\t"
							@echo "$(COL_0)m" "COMMAND + V" "$(UNSET)"
							@echo "\n"
							@printf "$(shell pwd)/$@" | pbcopy

$(OBJ_DIR)/%.o			:	%.c
							gcc $(FLAGS) -I $(INCLUDE) -MD -c $< -o $@

$(OBJ_DIR)				:
							@mkdir -p $(OBJ_DIR)/

include $(DEP)

# ________________________________________________________________CLEANS TARGETS

clean					:
							@rm -rf $(OBJ_DIR)
							@echo "$(COL_1);3;1mobject\033[23;22m files for \033[3;1m$(NAME)\033[23;22m have been deleted\033[0m"

check_obj_dir			:
							@if [ -d $(dir $(OBJ_DIR)) ] && [ -z "$(shell ls -A $(dir $(OBJ_DIR)) 2>stderr)" ]; then rm -rf $(dir $(OBJ_DIR)) ; fi
							@rm -f stderr

fclean					:	clean check_obj_dir
							@rm -f $(NAME)
							@echo "$(COL_1);3;1m$(NAME)\033[23;22m have been deleted\033[0m"

re						:	fclean all