##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile for my_printf
##

SRC = my_printf.c \
	  lib/my/my_put_double.c \
	  lib/my/my_put_float.c \
	  lib/my/my_put_h_hh.c \
	  lib/my/my_put_hash.c \
	  lib/my/my_put_hex.c \
	  lib/my/my_put_l.c \
	  lib/my/my_put_nbr.c \
	  lib/my/my_put_octal.c \
	  lib/my/my_put_plus.c \
	  lib/my/my_put_pointer.c \
	  lib/my/my_put_sci.c \
	  lib/my/my_put_uint.c \
	  lib/my/my_putchar.c \
	  lib/my/my_putstr.c

OBJ = $(SRC:.c=.o)

NAME_LIB = libmy.a

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	make clean

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_LIB)

re: fclean all
