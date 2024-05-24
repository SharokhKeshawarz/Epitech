/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** main.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

int secret_command(__pid_t child_pid, char ***env)
{
    char *exe = NULL;
    char *command[] = {"curl", "ASCII.live/can-you-hear-me", NULL};
    size_t len = 0;
    char *line = NULL;

    if (child_pid != 0) {
        exe = search_path(*env, "curl");
        child_pid = fork();
        if (child_pid == 0) {
            execve(exe, command, *env);
            exit(1);
        }
        if (getline(&line, &len, stdin)) {
            kill(child_pid, SIGTERM);
            free(line);
            free(exe);
        }
    }
    return 0;
}
