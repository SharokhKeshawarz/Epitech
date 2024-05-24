##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	main.c \
		my_putchar.c \
		my_put_nbr.c \
		my_strlen.c \
		my_strncmp.c \
		my_swap.c \
		my_strupcase.c \
		my_str_isupper.c \
		my_str_isalpha.c \
		my_str_isprintable.c \
		my_strlowcase.c \
		my_str_isnum.c \
		my_strcmp.c \
		my_str_islower.c \
		my_is_prime.c \
		my_compute_square_root.c \
		my_getnbr.c \
		my_find_prime_sup.c \
		my_compute_power_rec.c \
		my_strdup.c \
		libmore.c \
		my_str_to_word_array.c \
		my_strdupcaraccp.c

OBJ	= $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
