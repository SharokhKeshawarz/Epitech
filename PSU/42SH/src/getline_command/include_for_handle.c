/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** delimite commands
*/

#include "../include/pmy.h"
#include "../include/my.h"

int handle_par(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg)
{
    (*act)->next = init_line_command(PAR);
    for (int a = *argv_in_comm; a < *max_arg; a++)
        (*piped)->comm[a] = NULL;
    *act = (*act)->next;
    *piped = *act;
    *argv_in_comm = 0;
    return 1;
}

static void include_or(InputOutputHandler_t *handler, char *arg,
    char **argv, int a)
{
    if (my_strcmp("||", arg + 1) == 0 && arg[0] == 0x01 && argv[a + 1]) {
        handler->test += handle_or(&handler->act, &handler->piped,
        &handler->argv_in_comm, &handler->len_malloc);
    } else
        handle_input_output(handler->piped, arg, &handler->test,
        &handler->argv_in_comm);
}

static void include_and(InputOutputHandler_t *handler, char *arg,
    char **argv, int a)
{
    if (my_strcmp("&&", arg + 1) == 0 && arg[0] == 0x01 && argv[a + 1]) {
        if (my_strchr(argv[a + 1][0], "(") == 0)
            handler->test += handle_and(&handler->act, &handler->piped,
            &handler->argv_in_comm, &handler->len_malloc);
        else
            handler->test += handle_par(&handler->act, &handler->piped,
            &handler->argv_in_comm, &handler->len_malloc);
    } else
        include_or(handler, arg, argv, a);
}

static void include_semicolon(InputOutputHandler_t *handler, char *arg,
    char **argv, int a)
{
    if (my_strcmp(";", arg + 1) == 0 && arg[0] == 0x01 && argv[a + 1]) {
        if (my_strchr(argv[a + 1][0], "(") == 0)
            handler->test += handle_semicolon(&handler->act, &handler->piped,
            &handler->argv_in_comm, &handler->len_malloc);
        else
            handler->test += handle_par(&handler->act, &handler->piped,
            &handler->argv_in_comm, &handler->len_malloc);
    } else
        include_and(handler, arg, argv, a);
}

void include_pipe(InputOutputHandler_t *handler, char *arg,
    char **argv, int a)
{
    if (my_strcmp("|", arg + 1) == 0 && arg[0] == 0x01 && argv[a + 1]) {
        handler->test += handle_pipe(&handler->piped, &handler->act,
        &handler->argv_in_comm, &handler->len_malloc);
    } else
        include_semicolon(handler, arg, argv, a);
}
