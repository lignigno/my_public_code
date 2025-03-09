# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 03:00:56 by lignigno          #+#    #+#              #
#    Updated: 2021/06/05 09:58:55 by lignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY		: all clean fclean re

GREEN_COL	:= \033[38;2;0;145;15;1m
UNSET		:= \033[m

CLIENT		:= client
CLIENT_SRC	:= client.c
CLIENT_OBJ	:= $(addprefix obj/, $(CLIENT_SRC:.c=.o))

SERVER		:= server
SERVER_SRC	:= server.c
SERVER_OBJ	:= $(addprefix obj/, $(SERVER_SRC:.c=.o))

UTILS_SRC	:= utils.c
UTILS_OBJ	:= $(addprefix obj/, $(UTILS_SRC:.c=.o))

FLAGS		:= -Wall -Wextra -Werror

all			: obj/ $(UTILS_OBJ) $(CLIENT) $(SERVER)

obj/ :
	@mkdir obj/

$(CLIENT)	: $(CLIENT_OBJ)
	@gcc $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT)
	@echo "$(GREEN_COL)THE CLIENT IS READY$(UNSET)"

$(SERVER)	: $(SERVER_OBJ) 
	@gcc $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER)
	@echo "$(GREEN_COL)THE SERVER IS READY$(UNSET)"

obj/%.o		: %.c header.h
	@gcc $(FLAGS) -c $< -o $@

clean		:
	rm -rf obj/

fclean		: clean
	rm -rf $(CLIENT) $(SERVER)

re			: fclean all