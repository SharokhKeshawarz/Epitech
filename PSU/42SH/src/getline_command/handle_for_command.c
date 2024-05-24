/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** delimite commands
*/

#include "../include/pmy.h"
#include "../include/my.h"

int handle_pipe(line_com_t **piped, line_com_t **act, int *argv_in_comm,
    int *max_arg)
{
    (*piped)->pipe = init_line_command(NONE);
    for (int a = *argv_in_comm; a < *max_arg; a++)
        (*piped)->comm[a] = NULL;
    *piped = (*piped)->pipe;
    *argv_in_comm = 0;
    return 1;
}

int handle_semicolon(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg)
{
    (*act)->next = init_line_command(MORE);
    for (int a = *argv_in_comm; a < *max_arg; a++)
        (*piped)->comm[a] = NULL;
    *act = (*act)->next;
    *piped = *act;
    *argv_in_comm = 0;
    return 1;
}

void handle_default(line_com_t *piped, char *arg, int *argv_in_comm)
{
    piped->comm[*argv_in_comm] = my_strdup(arg);
    (*argv_in_comm)++;
}

int handle_and(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg)
{
    (*act)->next = init_line_command(AND);
    for (int a = *argv_in_comm; a < *max_arg; a++)
        (*piped)->comm[a] = NULL;
    *act = (*act)->next;
    *piped = *act;
    *argv_in_comm = 0;
    return 1;
}

int handle_or(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg)
{
    (*act)->next = init_line_command(OR);
    for (int a = *argv_in_comm; a < *max_arg; a++)
        (*piped)->comm[a] = NULL;
    *act = (*act)->next;
    *piped = *act;
    *argv_in_comm = 0;
    return 1;
}
