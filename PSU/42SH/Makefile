##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

.SILENT: all

SRC	=	src/main.c \
		src/libmain.c \
		src/commands/my_commands.c \
		src/commands/env.c \
		src/commands/unsetenv.c \
		src/commands/cd.c \
		src/path.c \
		src/getline_command/transformchar.c	\
		src/child_execution.c \
		src/getline_command/manage_command_feat.c \
		src/child_next.c \
		src/set/set.c \
		bonus/echo.c \
		bonus/secret_command.c	\
		src/history/historic.c \
		src/history/exclamation.c	\
		src/getline_command/get_delimiter.c 	\
		src/getline_command/delimite_order_stuck.c \
		src/getline_command/handle_for_command.c	\
		src/getline_command/include_for_handle.c	\
		src/getline_command/backticks.c	\
		src/line_edit/ctrl_plus.c \
		src/line_edit/line_edit.c \
		src/line_edit/special_case.c	\
		src/line_edit/arrows.c	\
		src/line_edit/condition_key.c	\
		src/line_edit/my_prompt.c	\
		src/classic_getline.c	\
		src/gettheline.c	\
		src/last_free.c	\
		src/globbings/globbings.c	\
		src/alias.c	\
		src/new_command.c	\
		src/utility_str.c	\

NAME = 42sh

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc $(SRC) -o $(NAME) -I./include -L./lib -lmy

clean:
	make -C lib/ clean

fclean: clean
	make -C lib/ fclean
	-rm -f ./lib/libmy.a
	-rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
