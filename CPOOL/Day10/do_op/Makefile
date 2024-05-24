##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiles do_op.c
##

NAME = do-op

CC = gcc

SRC	= do_op.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ../lib/my/ -lmy

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
