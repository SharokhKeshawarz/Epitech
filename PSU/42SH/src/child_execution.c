/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** main.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

static int
next_child(__pid_t child_pid, char ***env)
{
    int nbrterm = 0;
    int status = 0;

    if (waitpid(child_pid, &status, 0) != -1 && WIFEXITED(status) &&
    WEXITSTATUS(status) != 0)
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status))
        nbrterm = WTERMSIG(status);
    if (WIFSIGNALED(status) && nbrterm == 11 && !__WCOREDUMP(status))
        write(2, "Segmentation fault\n", 19);
    if (WIFSIGNALED(status) && nbrterm == 11 && __WCOREDUMP(status))
        write(2, "Segmentation fault (core dumped)\n", 33);
    if (WIFSIGNALED(status) && nbrterm == 11)
        return 0;
    return 0;
}

static int calculate_num_commands(line_com_t *command)
{
    int num_commands = 1;
    line_com_t *listpi = command;

    for (; listpi->pipe; listpi = listpi->pipe) {
        num_commands++;
    }
    return num_commands;
}

static void create_pipes(int num_commands, int ***pipes)
{
    *pipes = malloc(sizeof(int *) * (num_commands - 1));
    for (int i = 0; i < num_commands - 1; i++) {
        (*pipes)[i] = malloc(sizeof(int) * 2);
        if (pipe((*pipes)[i]) == -1) {
            perror("pipe");
            exit(84);
        }
    }
}

static void free_pipes(int num_commands, int **pipes)
{
    for (int i = 0; i < num_commands - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
        free(pipes[i]);
    }
    free(pipes);
}

static void
execute_child_command(int params[2], line_com_t **command,
    char ***env, int **pipes)
{
    int i = params[0];
    int num_commands = params[1];

    if (i != 0) {
        dup2(pipes[i - 1][0], STDIN_FILENO);
        *command = (*command)->pipe;
    }
    if (i != num_commands - 1)
        dup2(pipes[i][1], STDOUT_FILENO);
    check_in_out(command, i, pipes);
    close_pipes(pipes, num_commands, command);
    crochet(command, env);
    check_error(command);
    exit(1);
}

static int
test_my_commands(line_com_t *command, char ***env, int child_pid, int test)
{
    line_com_t *listpi = command;

    for (; listpi->next; listpi = listpi->next);
    if (!list_my_commands(listpi->comm, listpi->disp_com))
        return my_commands(listpi->comm, listpi->disp_com, env, child_pid);
    if (!list_my_commands(command->comm, command->disp_com))
        return my_commands(command->comm, command->disp_com, env, child_pid);
    return -1000;
}

static int create_with_fork(void)
{
    int child_pid = fork();

    if (child_pid == -1)
        exit(my_perror("Fork error", NULL, NULL, NULL) + 83);
    return child_pid;
}

static void loop_getl(char *buffer, line_com_t **comm)
{
    char *line = NULL;
    size_t line_len = 0;
    ssize_t byt = 0;

    byt = getline(&line, &line_len, stdin);
    while (byt != -1) {
        line[byt - 1] = '\0';
        if (my_strcmp(line, (*comm)->in) == 0)
            break;
        buffer = my_setstringend(buffer, line);
        myy_strcat(buffer, "\n");
        if (isatty(0))
            write(1, "? ", 2);
        byt = getline(&line, &line_len, stdin);
    }
    if (line && byt != -1);
        free(line);
}

static void for_input(int i, line_com_t **command, int fd, int child_pid)
{
    char *buffer = malloc(sizeof(char) * MAX_BUFFER);

    if ((*command)->in && (*command)->in_t == DOUBLE && i == 0 &&
        child_pid == 0) {
        buffer[0] = '\0';
        if (isatty(0))
            write(1, "? ", 2);
        loop_getl(buffer, command);
        fd = open("lib/temp_execute.mysh", O_WRONLY | O_CREAT | O_TRUNC,
        S_IRUSR | S_IWUSR);
        if (fd == -1)
            exit(my_perror("open", NULL, NULL, NULL));
        if (write(fd, buffer, my_strlen(buffer)) == -1) {
            close(fd);
            exit(my_perror("write", NULL, NULL, NULL));
        }
        close(fd);
    }
    free(buffer);
}

int
child_result(int child_pid, line_com_t *command, char ***env, int test)
{
    int num_commands = calculate_num_commands(command);
    int **pipes;
    int params[2] = {0};

    if (test <= -1000)
        return test % 10;
    test = test_my_commands(command, env, child_pid, test);
    if (test != -1000)
        return test;
    create_pipes(num_commands, &pipes);
    params[1] = num_commands;
    for (int i = 0; i < num_commands; i++) {
        params[0] = i;
        child_pid = create_with_fork();
        for_input(i, &command, -1, child_pid);
        if (child_pid == 0)
            execute_child_command(params, &command, env, pipes);
    }
    free_pipes(num_commands, pipes);
    return next_child(child_pid, env);
}
