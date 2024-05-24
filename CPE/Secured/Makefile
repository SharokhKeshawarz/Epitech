##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for libmy
##

SRC = hashtable_crud.c \
      hashtable.c \
	  my_put_nbr.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_strcmp.c \
	  my_strdup.c \
	  my_strlen.c

OBJ = $(SRC:.c=.o)

NAME_LIB = libhashtable.a

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	gcc -c $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	make clean

clean :
$(shell rm *.o)
