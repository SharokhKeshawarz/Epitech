/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** main.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

static int check_error_echo(line_com_t *list, bool more)
{
    if (list->comm[1] && list->comm[2] && list->comm[3] && more)
        return my_perror("history: Too many arguments.\n", NULL, NULL, NULL);
    if (my_str_isnum(list->comm[1]) == 0 && more)
        return my_perror("history: Badly formed number.\n", NULL, NULL, NULL);
    if ((list->comm[1] && list->comm[2] && list->comm[3]) ||
    (my_str_isnum(list->comm[1]) == 0))
        return 1;
    return 0;
}

static void free_local_vars(char *buffer, line_com_t *list)
{
    free(buffer);
    for (int i = 0; list->local_env[i] != NULL; i++)
        free(list->local_env[i]);
    free(list->local_env);
}

static void print_token(char **token)
{
    if ((*token) == NULL)
        return;
    printf("%s\n", (*token));
}

static int echo_local_vars_tokenize(char **token, line_com_t *list, int i)
{
    (*token) = strtok(list->local_env[i], "=");
    while ((*token) != NULL) {
        if (strcmp((*token), list->comm[1] + 1) == 0) {
            (*token) = strtok(NULL, "=");
            print_token(token);
            return -1000;
        }
        (*token) = strtok(NULL, "=");
    }
}

static int echo_local_vars(line_com_t *list)
{
    int fd = open(".local-env", O_RDONLY, 0644);
    struct stat st;
    char *buffer;
    ssize_t bytes_read;
    char *token;

    stat(".local-env", &st);
    buffer = malloc(st.st_size + 1);
    bytes_read = read(fd, buffer, st.st_size + 1);
    buffer[st.st_size] = '\0';
    list->local_env = my_str_to_word_array(buffer, "\n");
    if (list->local_env == NULL)
        return 84;
    for (int i = 0; list->local_env[i] != NULL; i++)
        if (echo_local_vars_tokenize(&token, list, i) == -1000)
            return -1000;
    free_local_vars(buffer, list);
}

int check_pid_and_echo(__pid_t child_pid, line_com_t *command, int test,
    history_t **historic)
{
    for (line_com_t *list = command; list; list = list->pipe) {
        if (list->comm[0] && strcmp(list->comm[0], "history") == 0 &&
        check_error_echo(list, false) == 0) {
            view_history(historic, list->comm[1]);
            return -1000;
        }
        if (list->comm[0] && my_strcmp(list->comm[0], "history") == 0 &&
        check_error_echo(list, true) != 0)
            return -1001;
        if (list->comm[1] && my_strcmp(list->disp_com, "echo") == 0 &&
        strcmp(list->comm[1], "$?") == 0) {
            printf("%d\n", test);
            return -1000;
        }
        if (list->comm[1] && my_strcmp(list->disp_com, "echo") == 0 &&
        list->comm[1][0] == '$') {
            echo_local_vars(list);
            return -1000;
        }
    }
}
