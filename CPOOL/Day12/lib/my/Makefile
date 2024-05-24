##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiles all libs to make libmy.a
##

SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

LIB = libmy.a

all: $(LIB)

$(LIB): $(OBJ)
	gcc -c $(OBJ)
	ar rc $(LIB) $(OBJ)
	make clean

clean: $(shell rm -f $(OBJ))
