/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** my_commands.c
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

int print_env(char **env, char **argum)
{
    if (argum[1])
        return 84;
    for (int i = 0; env[i]; ++i)
        my_printf("%s\n", env[i]);
    return 0;
}

void myy_strcat(char *s1, const char *s2)
{
    int a = 0;
    int b = 0;

    if (!s1 || !s2)
        return;
    while (s1[a])
        a++;
    for (; s2[b]; b++) {
        s1[a + b] = s2[b];
    }
    s1[a + b] = '\0';
}

static char **cpy_env_more_alloc(char **env)
{
    int i = 0;
    int len = 0;
    char **cpy_env = NULL;

    for (; env[i]; i++);
    cpy_env = malloc(sizeof(char *) * (i + 2));
    len = i;
    for (i = 0; env[i] && i < len; i++)
        cpy_env[i] = env[i];
    cpy_env[i] = NULL;
    free(env);
    return cpy_env;
}

static int set_env_error(char *key)
{
    if (!((key[0] >= 'a' && key[0] <= 'z') || (key[0] <= 'Z' && key[0] >= 'A')
    || key[0] == '_')) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    if (my_str_isalpha(key) == 0) {
        write(2, "setenv: Variable name must contain ", 35);
        write(2, "alphanumeric characters.\n", 25);
        return 1;
    }
    return 0;
}

static int set_env_exist(char **envi, const char *pwd, char *key, int a)
{
    free(envi[a]);
    envi[a] = malloc(sizeof(char) * (my_strlen(pwd) + my_strlen(key) + 2));
    my_strcpy(envi[a], key);
    myy_strcat(envi[a], "=");
    myy_strcat(envi[a], pwd);
    return 0;
}

int set_env(char *key, char ***env, const char *pwd, int b)
{
    int a = -1;
    char **envi = *env;

    if (set_env_error(key) == 1)
        return 1;
    for (; envi[b]; b++)
        if (my_strncmp(key, envi[b], my_strlen(key)) == 0 &&
        envi[b][my_strlen(key)] == '=')
            a = b;
    if (a != -1)
        return set_env_exist(envi, pwd, key, a);
    *env = cpy_env_more_alloc(envi);
    envi = *env;
    envi[b] = malloc(sizeof(char) * (my_strlen(pwd) + my_strlen(key) + 2));
    my_strcpy(envi[b], key);
    myy_strcat(envi[b], "=");
    myy_strcat(envi[b], pwd);
    envi[b + 1] = NULL;
    return 0;
}

int too_many_setenv(void)
{
    write(2, "setenv: Too many arguments.\n", 28);
    return 1;
}
