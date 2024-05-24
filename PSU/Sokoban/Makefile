##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for the project
##

NAME	=	my_sokoban

SRC	= $(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): 	$(SRC)
	make -C lib/my
	gcc -g -I./include -Llib/my $(SRC) -lncurses -o $(NAME) -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	clean fclean
	make -C lib/my
	gcc -I./include -Llib/my $(SRC) -lncurses -o $(NAME) -lmy

.PHONY:	clean fclean re all
