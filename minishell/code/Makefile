#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:50:25 by lignigno          #+#    #+#              #
#    Updated: 2021/05/31 11:50:26 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY :	all clean fclean re

# _____________________________________________________________________VARIABLES

GREEN_COL := \033[38;2;0;145;15
YELLOW_COL := \033[38;2;204;194;0

NAME := minishell

VPATH =	srcs/ \
		srcs/build-in/ \
		srcs/errorka/ \
		srcs/execute \
		srcs/get_command_line \
		srcs/init/ \
		srcs/other \
		srcs/parser/ \
		srcs/utils/

SRC :=	main.c \
		build-in/call_cd.c \
		build-in/call_echo.c \
		build-in/call_env.c \
		build-in/call_exit.c \
		build-in/call_export.c \
		build-in/call_pwd.c \
		build-in/call_unset.c \
		errorka/errorka.c \
		errorka/minishell_errorka.c \
		execute/call_command.c \
		execute/call_other.c \
		execute/create_pipes.c \
		execute/execute_command.c \
		execute/redirects.c \
		get_command_line/change_command_line.c \
		get_command_line/get_command_line.c \
		get_command_line/my_termcaps.c \
		get_command_line/set_unset_terminal_settigs.c \
		init/init.c \
		init/init_env.c \
		parser/count_args.c \
		parser/cut_redirection.c \
		parser/get_args.c \
		parser/get_one_arg.c \
		parser/get_redirects.c \
		parser/parser.c \
		parser/processing_of_command_line.c \
		parser/replace_dollar_variable.c \
		parser/replace.c \
		parser/validate_sintax.c \
		utils/add_char.c \
		utils/add_with_sorting.c \
		utils/add_process.c \
		utils/add_var.c \
		utils/add_without_sorting.c \
		utils/change_existing_variable.c \
		utils/change_pwd_and_oldpwd.c \
		utils/cmp_ch_with.c \
		utils/command_exists.c \
		utils/destroy_processes.c \
		utils/free_pipes.c \
		utils/free_processes.c \
		utils/ft_bzero.c \
		utils/ft_itoa.c \
		utils/ft_putchar.c \
		utils/ft_split.c \
		utils/ft_strcmp.c \
		utils/ft_strncmp.c \
		utils/ft_substr.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/get_value.c \
		utils/get_variable.c \
		utils/name_with_path.c \
		utils/new_env.c \
		utils/not_valid_identifier.c \
		utils/o_my_wait.c \
		utils/skip_redirects.c \
		utils/skip_spaces.c \
		utils/valid_char.c

OBJ := $(addprefix obj/, $(notdir $(SRC:.c=.o)))

INCLUDE := srcs/headers/
FLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : obj/ $(OBJ)
	@gcc -ltermcap $(OBJ) -o $(NAME)
	@echo "$(GREEN_COL)m"
	@echo "   /---------------------\\"
	@echo "   | everything is ready |"
	@echo "   \\---------------------/\n"
	@echo "       ˅˅˅˅˅˅˅˅˅˅˅˅˅"
	@echo "       ˃$(YELLOW_COL)mCOMMAND + V$(GREEN_COL);1m˂"
	@echo "       ˄˄˄˄˄˄˄˄˄˄˄˄˄\033[m\n"
	@printf %s ./$(NAME) | pbcopy


obj/%.o : %.c $(INCLUDE)/*.h
	gcc $(FLAGS) -I $(INCLUDE) -c $< -o $(addprefix obj/, $(notdir $@))

obj/ :
	@mkdir obj/

# ________________________________________________________________CLEANS TARGETS

clean :
	@rm -rf obj/
	@echo "$(YELLOW_COL);4;1mobject\033[22m files for \033[4;1m$(NAME)\033[22m have been deleted\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(YELLOW_COL);4;1m$(NAME)\033[22m have been deleted\033[0m"

re : fclean all
