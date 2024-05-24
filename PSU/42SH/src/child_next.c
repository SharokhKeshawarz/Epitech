/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** main.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

void close_pipes(int **pipes, int num_commands, line_com_t **command)
{
    for (int a = 0; a < num_commands - 1; a++) {
        close(pipes[a][0]);
        if (!((*command)->in && a == 0 && (*command)->in_t == DOUBLE))
            close(pipes[a][1]);
    }
}

static void check_lsimple(line_com_t **command)
{
    int fd = open((*command)->in, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

static void check_ldouble(line_com_t **command)
{
    int fd = open("lib/temp_execute.mysh", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

int check_error(line_com_t **command)
{
    if (errno != ENOENT && errno != ENOEXEC)
        my_perror((*command)->disp_com, ": ", strerror(errno), ".\n");
    if (errno == ENOEXEC)
        exit(my_perror((*command)->disp_com, NULL,
        ": Exec format error.", " Wrong Architecture.\n") + 125);
    if (access((*command)->comm[0], F_OK) != 0)
        my_perror((*command)->disp_com, ": Command not found.\n", NULL, NULL);
}

static void check_rsimple(line_com_t **command)
{
    int fd = open((*command)->out, O_WRONLY | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR);

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
}

static void check_rdouble(line_com_t **command)
{
    int fd = open((*command)->out, O_WRONLY | O_CREAT | O_APPEND,
    S_IRUSR | S_IWUSR);

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
}

void check_in_out(line_com_t **command, int i, int **pipes)
{
    if ((*command)->in && (*command)->in_t == SIMPLE && i == 0)
        check_lsimple(command);
    if ((*command)->in && (*command)->in_t == DOUBLE && i == 0)
        check_ldouble(command);
    if ((*command)->out && (*command)->out_t == SIMPLE)
        check_rsimple(command);
    if ((*command)->out && (*command)->out_t == DOUBLE)
        check_rdouble(command);
}
