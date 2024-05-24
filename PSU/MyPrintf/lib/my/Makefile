##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for libmy
##

SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAME_LIB = libmy.a

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	gcc -c $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	make clean

clean :
	$(shell rm *.o)
