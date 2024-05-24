##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Builds Lib
##

NAME	= organized

CC      = gcc

SRC     = $(shell find . -type f -name '*.c')

RM      = rm -f

OBJ     = $(SRC:.c=.o)

LDFLAGS = -L./lib/my/ -lmy -L./shell -lshell

INCLUDE = -I./include -I./shell

LIBMY = lib/my/libmy.a

all: $(NAME)

$(NAME): $(SRC)
	make -C ./lib/my/
	$(CC) -g $(SRC) $(INCLUDE) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

aclean:
	$(RM) $(NAME)
	$(RM) $(LIBMY)

re: fclean all
