/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** lib.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

line_com_t *init_line_command(int type)
{
    line_com_t *new = malloc(sizeof(line_com_t));

    new->comm = NULL;
    new->in = NULL;
    new->out = NULL;
    new->out_t = NO_TYPE;
    new->in_t = NO_TYPE;
    new->next = NULL;
    new->pipe = NULL;
    new->type = type;
    return new;
}

bool stop_carac(char *str, int i)
{
    if (i > 0 && str[i - 1] && str[i - 1] == '\\')
        return false;
    if (str[i] && (str[i] == '<' || str[i] == '>' || str[i] == '|' ||
    str[i] == ';'))
        return true;
    return false;
}

static int in_dup(char *str, line_com_t *act)
{
    int len = 0;
    int space_ok = 0;

    if (act->in != NULL) {
        my_perror("Ambiguous input redirect.\n", NULL, NULL, NULL);
        return 84;
    }
    if (!str || !str[0] || stop_carac(str, 0)) {
        my_perror("Missing name for redirect.\n", NULL, NULL, NULL);
        return 84;
    }
    for (; str[len] && !stop_carac(str, len) && space_ok == 0; len++) {
        space_ok = ndup(space_ok, str, len);
    }
    act->in = my_strduplen(str, len);
    return 1;
}

static int out_dup(char *str, line_com_t *act)
{
    int len = 0;
    int space_ok = 0;

    if (act->out != NULL) {
        my_perror("Ambiguous input redirect.\n", NULL, NULL, NULL);
        return 84;
    }
    if (!str || !str[0] || stop_carac(str, 0)) {
        my_perror("Missing name for redirect.\n", NULL, NULL, NULL);
        return 84;
    }
    for (; str[len] && !stop_carac(str, len) && space_ok == 0; len++) {
        space_ok = ndup(space_ok, str, len);
    }
    act->out = my_strduplen(str, len);
    return 1;
}

void handle_input_output(line_com_t *piped, char *arg, int *test,
    int *argv_in_comm)
{
    if (piped->out_t != NO_TYPE && piped->out == NULL)
        (*test) += out_dup(arg, piped);
    if (piped->in_t != NO_TYPE && piped->in == NULL)
        (*test) += in_dup(arg, piped);
    if (arg[0] == 0x01 && arg[1] == '<' && !arg[2]) {
        piped->in_t = SIMPLE;
        (*test)++;
    }
    if (my_strncmp("<<", arg + 1, 2) == 0 && !arg[3]) {
        piped->in_t = DOUBLE;
        (*test)++;
    }
    if (arg[0] == 0x01 && arg[1] == '>' && !arg[2]) {
        piped->out_t = SIMPLE;
        (*test)++;
    }
    if (my_strncmp(">>", arg, 2) == 0 && arg[2] && !arg[3]) {
        piped->out_t = DOUBLE;
        (*test)++;
    }
}

void process_argument(InputOutputHandler_t *handler, char *arg,
    char **argv, int a)
{
    handler->test = 0;
    if (!handler->piped->comm) {
        handler->piped->comm = malloc(sizeof(char *) *
        (handler->len_malloc + 1));
        if (!handler->piped->comm)
            exit(EXIT_FAILURE);
        handler->argv_in_comm = 0;
        handler->piped->comm[handler->len_malloc] = NULL;
    }
    include_pipe(handler, arg, argv, a);
    if (handler->test == 0)
        handle_default(handler->piped, arg, &handler->argv_in_comm);
}

line_com_t *magicinputoutput(char **argv)
{
    InputOutputHandler_t *handler = malloc(sizeof(InputOutputHandler_t));
    line_com_t *the_new_command = NULL;

    handler->new = init_line_command(MORE);
    handler->act = handler->new;
    handler->piped = handler->act;
    handler->len_malloc = 0;
    handler->argv_in_comm = 0;
    handler->test = 0;
    if (!(argv && argv[0]))
        return NULL;
    for (; argv[handler->len_malloc]; handler->len_malloc++);
    for (int a = 0; argv[a]; a++)
        process_argument(handler, argv[a], argv, a);
    if (handler->piped->comm)
        handler->piped->comm[handler->argv_in_comm] = NULL;
    the_new_command = handler->new;
    free(handler);
    return the_new_command;
}
