##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME = amazed

CC = gcc

SRC = $(shell find src -type f -name '*.c')

RM = rm -f

OBJ = $(SRC:.c=.o)

LDFLAGS = -L./lib/my/ -lmy

INCLUDE = -I./include

ARG = graph

FILE = labyrinth.txt

all: $(NAME)

$(NAME): $(SRC)
	make -C ./lib/my/
	$(CC) -g $(SRC) $(INCLUDE) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

vis:
	./$(NAME) < asset/$(FILE) | dot -Tdot > visuals/$(ARG).dot
