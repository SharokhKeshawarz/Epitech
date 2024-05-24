##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Builds Lib
##

NAME    = my_ls

CC      = gcc

SRC     = $(shell find . -type f -name '*.c')

RM      = rm -f

OBJ     = $(SRC:.c=.o)

LDFLAGS = -L./lib/my/ -lmy

INCLUDE = -I./include

all: $(NAME)

$(NAME): $(SRC)
	make -C ./lib/my/
	$(CC) $(SRC) $(INCLUDE) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
