/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** my_commands.c
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

static char *set_argum_unsetenv(char *argum, int len)
{
    char *new = malloc(sizeof(char) * (len));

    my_strcpy(new, argum);
    myy_strcat(new, "=");
    return new;
}

static int cpy_my_env(char **cpy_env, char **envi)
{
    int i = 0;
    int j = 0;

    for (i = 0; envi[i]; i++)
        if (envi[i][0] != '\0') {
            cpy_env[j] = envi[i];
            j++;
        } else
            free(envi[i]);
    return j;
}

static void search_argum_unsetenv(char *argum, char ***env, int i, int j)
{
    int len = my_strlen(argum) + 1;
    int test = -1;
    char **cpy_env = NULL;
    char **envi = *env;
    char *my_argum = set_argum_unsetenv(argum, len);

    for (; envi[i]; i++) {
        if (my_strncmp(my_argum, envi[i], len) == 0) {
            test = i;
            envi[i][0] = '\0';
        }
    }
    if (test != -1) {
        cpy_env = malloc(sizeof(char *) * (i));
        j = cpy_my_env(cpy_env, envi);
        cpy_env[j] = NULL;
        free(envi);
        *env = cpy_env;
    }
    free(my_argum);
}

int unset_env(char **argum, char ***env)
{
    if (!argum[1]) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    for (int a = 1; argum[a]; a++) {
        if (find_letter(argum[1], '*'))
            return 84;
        search_argum_unsetenv(argum[a], env, 0, 0);
    }
    return 0;
}
