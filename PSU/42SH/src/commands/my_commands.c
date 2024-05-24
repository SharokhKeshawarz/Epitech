/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** my_commands.c
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

bool list_my_commands(char **argum, char *first)
{
    if (my_strcmp("cd", first) == 0 ||
    my_strcmp("env", first) == 0 ||
    my_strcmp("setenv", first) == 0 ||
    my_strcmp("unsetenv", first) == 0 ||
    (my_strcmp("echo", first) == 0 && my_strcmp(argum[1], "$?") == 0) ||
    my_strcmp("history", first) == 0 ||
    my_strcmp("secret_command", first) == 0 || my_strcmp("set", first) == 0 ||
    (my_strcmp("echo", first) == 0 && argum != NULL && argum[1][0] == '$') ||
    my_strcmp("alias", first) == 0)
        return false;
    return true;
}

static char **
remalloc_chard(char **env, char *first)
{
    int a = 0;
    char **new_env = NULL;

    for (; env[a]; a++);
    new_env = malloc(sizeof(char *) * (a + 2));
    new_env[a] = NULL;
    a = my_strlen(first);
    new_env[0] = malloc(sizeof(char) * (a + 1));
    my_strcpy(new_env[0], first);
    new_env[0][a] = '\0';
    for (int b = 1; env[b]; b++) {
        a = my_strlen(env[b]);
        new_env[b] = malloc(sizeof(char) * (a + 1));
        my_strcpy(new_env[b], env[b]);
        new_env[b][a] = '\0';
    }
    return new_env;
}

static void getfreechar(char **strd)
{
    for (int b = 0; strd[b]; b++)
        free(strd[b]);
    free(strd);
}

static void my_commands_2(char **argum, char ***env, char *first, int *test)
{
    if (argum[0] && my_strcmp(argum[0], "cd") == 0)
        (*test) = cd_handler(argum, env);
    if (argum[0] && my_strcmp(argum[0], "set") == 0)
        (*test) = set_command(argum, env, first);
    if (argum[0] && my_strcmp(argum[0], "alias") == 0)
        (*test) = alias(argum);
}

int my_commands(char **argum, char *first, char ***env, __pid_t child_pid)
{
    int test = 0;

    argum = remalloc_chard(argum, first);
    my_commands_2(argum, env, first, &test);
    if (argum[0] && my_strcmp(argum[0], "env") == 0)
        test = print_env(*env, argum);
    if (argum[1] && my_strcmp(argum[0], "setenv") == 0
    && (!argum[3] || !argum[2]))
        test = set_env(argum[1], env, argum[2], 0);
    if (argum[1] && argum[2] && argum[3] && my_strcmp(argum[0], "setenv") == 0)
        test = too_many_setenv();
    if (argum[0] && my_strcmp(argum[0], "setenv") == 0 && !argum[1])
        test = print_env(*env, argum);
    if (argum[0] && my_strcmp(argum[0], "unsetenv") == 0)
        test = unset_env(argum, env);
    if (argum[0] && my_strcmp(argum[0], "secret_command") == 0)
        test = secret_command(child_pid, env);
    getfreechar(argum);
    return test;
}
