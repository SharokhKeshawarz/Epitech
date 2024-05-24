/*
** EPITECH PROJECT, 2024
** ampersand
** File description:
** ampersand
*/

#include "../../include/pmy.h"

static void print_args(char **argum)
{
    for (int i = 0; argum[i] != NULL; i++)
        printf("%s", argum);
    printf("\n");
}

int ampersand(char **argum, char ***env)
{
    pid_t pid = fork();
    static int counter = 0;
    int status;
    char **_env = *env;

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("[%d] %d\n", counter, getpid());
        counter++;
        execve(argum[0], argum, _env);
        perror("execve failed");
        exit(EXIT_FAILURE);
    } else {
        printf("[%d] + %d suspended (tty output) ", counter, pid);
        print_args(argum);
        waitpid(pid, &status, WUNTRACED);
    }
    return status;
}
