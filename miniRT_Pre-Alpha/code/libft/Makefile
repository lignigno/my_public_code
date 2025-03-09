# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 02:50:04 by lignigno          #+#    #+#              #
#    Updated: 2021/03/13 10:50:16 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus other_compil dir

NAME := libft.a

# _____________________________________________________________________VARIABLES

#<<<<<<<<[SRC]>>>>>>>>

SRC_LIB := 	ft_memset.c				ft_bzero.c 			ft_memcpy.c \
		ft_memccpy.c 			ft_memmove.c 		ft_memchr.c \
		ft_memcmp.c 			ft_strlen.c 		ft_isalpha.c \
		ft_isdigit.c 			ft_isalnum.c 		ft_isascii.c \
		ft_isprint.c 			ft_toupper.c 		ft_tolower.c \
		ft_strchr.c 			ft_strrchr.c 		ft_strncmp.c \
		ft_strlcpy.c 			ft_strlcat.c 		ft_strnstr.c \
		ft_atoi.c 				ft_calloc.c			ft_strdup.c \
		ft_substr.c 			ft_strjoin.c 		ft_strtrim.c \
		ft_split.c 				ft_itoa.c 			ft_strmapi.c \
		ft_putchar_fd.c 		ft_putstr_fd.c 		ft_putendl_fd.c \
		ft_putnbr_fd.c 			dummy_bonus.c 		printninvis_bonus.c \
		add_char_bonus.c		ft_lstnew.c 		ft_lstadd_front.c \
		ft_lstsize.c 			ft_lstlast.c 		ft_lstadd_back.c \
		ft_lstdelone.c 			ft_lstclear.c 		ft_lstiter.c \
		ft_lstmap.c				cmp_ch_with.c		swap.c \
		checks.c

SRC_GNL := gnl.c gnl_utils.c

#<<<<<<<<[OBJ]>>>>>>>>

OBJ_LIB := $(SRC_LIB:.c=.o)

OBJ_GNL := $(SRC_GNL:.c=.o)

OBJ := $(OBJ_LIB)
OBJ += $(OBJ_GNL)

OBJ := $(addprefix obj/, $(OBJ))

#<<<<<<<<[FLAGS]>>>>>>>>

LIB_FLAGS := -O3 -Wall -Wextra -Werror

export LIB_FLAGS

# _______________________________________________________________________TARGETS

all: $(NAME)

$(NAME): obj/ other_compil $(OBJ)
	@ar rus $(NAME) $(OBJ)
	@echo "\033[38;2;0;145;15m$(NAME) was created\033[0m"

obj/%.o : %.c libft.h gnl/gnl.h
	gcc $(LIB_FLAGS) -c $< -o $@

other_compil:
	@make -C gnl/

obj/ :
	@mkdir obj/

#<<<<<<<<[OTHER]>>>>>>>>

clean:
	@rm -rf obj/
	@echo "\033[33;4;1mobject\033[0;33;1m files for \033[33;4;1m$(NAME)\033[0;33;1m have been deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;4;1m$(NAME)\033[0;33;1m have been deleted\033[0m"

re: fclean all
