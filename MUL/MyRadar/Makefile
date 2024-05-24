##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME    = my_radar

CC      = gcc

CFLAGS = -g

SRC     = $(shell find src -type f -name '*.c')

RM      = rm -f

OBJ     = $(SRC:.c=.o)

LDFLAGS = -Llib/my -lm -lmy

SFML_FLAGS = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

INCLUDE = -I./include

all: $(NAME)

$(NAME): $(SRC)
	make -C lib/my
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME) $(LDFLAGS) $(SFML_FLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
