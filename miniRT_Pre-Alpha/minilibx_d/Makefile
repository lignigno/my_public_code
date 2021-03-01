


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)
	@mv $(NAME) ../

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz

%.o: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	@rm -f ../$(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
	@echo "\033[33;1;4mobject\033[0;33;1m files for \033[4m$(NAME)\033[0;33;1m \
	and \033[4m$(NAME)\033[0;33;1m itself have been deleted\033[0m"

