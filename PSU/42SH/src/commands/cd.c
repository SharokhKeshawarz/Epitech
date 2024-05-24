/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** my_commands.c
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

static int my_home_cd(char ***env, char *cwd)
{
    char **envi = *env;

    for (int a = 0; envi[a]; a++) {
        if (my_strncmp("HOME", envi[a], 4) != 0)
            continue;
        if (access(envi[a] + 5, X_OK) != 0 && access(envi[a] + 5, F_OK) == 0)
            return my_perror(envi[a] + 5, ": Permission denied.\n",
            NULL, NULL);
        if (chdir(envi[a] + 5) == -1)
            return my_perror(envi[a] + 7, ": No such file or directory.\n",
            NULL, NULL);
        set_env("OLDPWD", env, cwd, 0);
        set_env("PWD", env, envi[a] + 5, 0);
        return 0;
    }
}

static int my_back_cd(char ***env, char **argum)
{
    char cwd[1024];
    char **envi = *env;

    for (int a = 0; envi[a]; a++) {
        if (my_strncmp("OLDPWD", envi[a], 6) != 0)
            continue;
        if (getcwd(cwd, sizeof(cwd)) == NULL)
            perror("getcwd");
        if (access(envi[a] + 7, X_OK) != 0 && access(envi[a] + 7, F_OK) == 0)
            return my_perror(envi[a] + 7, ": Permission denied.\n", NULL,
            NULL);
        if (chdir(envi[a] + 7) == -1)
        return my_perror(envi[a] + 7, ": No such file or directory.\n",
        NULL, NULL);
        set_env("OLDPWD", env, cwd, 0);
        if (getcwd(cwd, sizeof(cwd)))
            set_env("PWD", env, cwd, 0);
        return 0;
    }
    return my_perror(": No such file or directory.\n", NULL, NULL, NULL);
}

static int check_stat(char *argum)
{
    struct stat path_stat;

    if (stat(argum, &path_stat) != 0)
    return my_perror(argum, ": No such file or directory.\n", NULL, NULL);
    if (!S_ISDIR(path_stat.st_mode))
        return my_perror(argum, ": Not a directory.\n", NULL, NULL);
}

int cd_handler(char **argum, char ***env)
{
    char cwd[1024];

    if (argum[1] && argum[2])
        return my_perror("cd: Too many arguments.\n", NULL, NULL, NULL);
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return 1;
    if (!argum[1] || my_strcmp("~", argum[1]) == 0)
        return my_home_cd(env, cwd);
    if (my_strcmp("-", argum[1]) == 0)
        return my_back_cd(env, argum);
    if (check_stat(argum[1]) == 1)
        return 1;
    if (access(argum[1], X_OK) != 0 && access(argum[1], F_OK) == 0)
        return my_perror(argum[1], ": Permission denied.\n", NULL, NULL);
    if (chdir(argum[1]) == -1)
    return my_perror(argum[1], ": No such file or directory.\n", NULL, NULL);
    set_env("OLDPWD", env, cwd, 0);
    if (getcwd(cwd, sizeof(cwd)))
        set_env("PWD", env, cwd, 0);
    return 0;
}
