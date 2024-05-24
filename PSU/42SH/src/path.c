/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** path.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

int my_perror(char *str, char *str2, char *str3, char *str4)
{
    int len = 0;

    if (str) {
        len = my_strlen(str);
        write(2, str, len);
    }
    if (str2) {
        len = my_strlen(str2);
        write(2, str2, len);
    }
    if (str3) {
        len = my_strlen(str3);
        write(2, str3, len);
    }
    if (str4) {
        len = my_strlen(str4);
        write(2, str4, len);
    }
    return 1;
}

static char *is_executable(char *test, char *exe, int len)
{
    int len_exe = my_strlen(exe);
    char *temp = malloc(sizeof(char) * (len + len_exe + 2));
    struct stat file_info = {0};
    int check = 0;

    if (!temp || len < 1 || len_exe < 1)
        return NULL;
    my_strncpy(temp, test, len);
    myy_strcat(temp, "/");
    myy_strcat(temp, exe);
    if (access(temp, F_OK) != 0 || access(temp, X_OK) != 0 ||
    stat(temp, &file_info) != 0)
        check++;
    if (!(S_ISREG(file_info.st_mode) && (file_info.st_mode & S_IXUSR)))
        check++;
    if (check == 0)
        return temp;
    free(temp);
    return NULL;
}

char *check_in_path(char *env, int i, char *exe)
{
    char *test = NULL;
    int len = 0;
    char *filename = NULL;

    for (i = 4; env[i - 1] && env[i - 1] != '\n'; i++) {
        if (env[i] != ':' && i != 4)
            continue;
        if (env[i + 1] && my_strncmp(&env[i + 1], "./", 2) != 0 &&
        my_strncmp(&env[i + 1], "../", 3) != 0) {
            test = &env[i + 1];
            len = my_strnlen(test, ':');
            filename = is_executable(test, exe, len);
        }
        if (filename != NULL) {
            return filename;
        }
        len = 0;
    }
    return NULL;
}

char *search_path(char **env, char *exe)
{
    char *path = NULL;
    int i = -1;
    int a = 0;

    for (; env[a]; a++) {
        if (my_strncmp(env[a], "PATH=", 5) == 0) {
            i = a;
            break;
        }
    }
    if (i != -1) {
        return check_in_path(env[a], i, exe);
    }
    return NULL;
}

static char *my_homedup(char **env, char *exe, int len_exe)
{
    int e = -1;
    int len = 0;
    char *path = NULL;

    for (int a = 0; env[a]; a++)
        if (my_strncmp("HOME", env[a], 4) == 0)
            e = a;
    if (e != -1) {
        len = my_strlen(env[e] + 5);
        path = my_strduplen(env[e] + 5, len + len_exe);
        myy_strcat(path, exe + 1);
        return path;
    }
    return NULL;
}

char *setbin(char *exe, char **env)
{
    char *res = NULL;
    int len = my_strlen(exe);

    if (!exe)
        return NULL;
    if (my_strncmp(exe, "./", 2) != 0 && my_strncmp(exe, "/", 1) != 0 &&
    my_strncmp(exe, "../", 3) != 0 && my_strncmp(exe, "~", 1) != 0) {
        res = search_path(env, exe);
        if (res != NULL)
            return res;
    }
    if (my_strncmp(exe, "~", 1) == 0)
        res = my_homedup(env, exe, len);
    if (res != NULL)
        return res;
    return my_strdup(exe);
}
