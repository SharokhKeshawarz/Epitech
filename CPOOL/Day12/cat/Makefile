##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Builds Cat
##

NAME	= cat

CC	= gcc

SRC	= cat.c

RM	= rm -f

OBJ	= $(SRC:.c=.o)

LDFLAGS	= -L ../lib/my/ -lmy

all: $(NAME)

$(NAME):
	make -C ../lib/my/
	$(CC) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
