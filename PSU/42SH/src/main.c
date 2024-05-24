/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** main.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

static void
check_argum(line_com_t *command, char **env)
{
    char *search;

    for (line_com_t *list = command; list; list = list->next) {
        for (line_com_t *list_pi = list; list_pi; list_pi = list_pi->pipe) {
            search = setbin(list_pi->comm[0], env);
            free(list_pi->comm[0]);
            list_pi->comm[0] = search;
        }
    }
}

static char **
remalloc_env(char **env, bool malloctrue)
{
    int a = 0;
    char **new_env = NULL;

    if (malloctrue) {
        for (; env[a]; a++);
        new_env = malloc(sizeof(char *) * (a + 2));
        new_env[a] = NULL;
        for (int b = 0; env[b]; b++) {
            a = my_strlen(env[b]);
            new_env[b] = malloc(sizeof(char) * (a + 1));
            my_strcpy(new_env[b], env[b]);
            new_env[b][a] = '\0';
        }
        return new_env;
    } else {
        for (int b = 0; env[b]; b++) {
            free(env[b]);
        }
        free(env);
    }
}

static void
free_command(line_com_t *command)
{
    if (command) {
        if (command->in)
            free(command->in);
        if (command->out)
            free(command->out);
        free_command(command->pipe);
        free_command(command->next);
        if (!command->comm)
            return;
        for (int a = 0; command->comm[a]; a++)
            free(command->comm[a]);
        free(command->comm);
        free(command->disp_com);
        free(command);
    }
}

static void
getfree(char *executable, char *testline, line_com_t *command)
{
    free_command(command);
    free(executable);
    free(testline);
}

static
history_t **create_history(void)
{
    history_t **hist = malloc(sizeof(history_t *));

    if (hist == NULL) {
        my_printf("Memory allocation failed\n");
        return NULL;
    }
    *hist = malloc(sizeof(history_t));
    if (*hist == NULL) {
        my_printf("Memory allocation failed\n");
        free(hist);
        return NULL;
    }
    (*hist)->line_com = NULL;
    (*hist)->clock = NULL;
    (*hist)->nb = 0;
    (*hist)->next = NULL;
    return hist;
}

static
void execution_free(char *executable, char *testline, line_com_t *command,
    history_t **historic)
{
    getfree(executable, testline, command);
    free_historic(historic);
}

static void forking_a_child(general_t *general, line_com_t *command,
    __pid_t child_pid, char ***env)
{
    check_argum(command, *env);
    for (line_com_t *list_m = command; list_m && ((general->test == 0 &&
    list_m->type == AND) || (general->test != 0 && list_m->type == OR) ||
    list_m->type == MORE || list_m->type == NONE); list_m = list_m->next) {
        general->test = check_pid_and_echo(child_pid, list_m, general->test,
        general->historic);
        general->test = child_result(child_pid, list_m, env, general->test);
    }
}

static void
execution(char ***env, line_com_t *command, char *testline, general_t *gen)
{
    __pid_t child_pid = 0;
    history_t **h = create_history();
    char *executable;

    gen->historic = h;
    executable = new_command(NULL, executable, testline, gen);
    while (executable && my_strncmp(executable, "exit ", 5) != 0) {
        command = transformchar(executable, 0, h, *env);
        gen->historic = h;
        if (!command) {
            executable = new_command(command, executable, testline, gen);
            executable = history_exclamtion(executable, h);
            continue;
        }
        forking_a_child(gen, command, child_pid, env);
        executable = new_command(command, executable, testline, gen);
        executable = history_exclamtion(executable, h);
    }
    execution_free(executable, testline, command, h);
}

int main(int ac, char **av __attribute__((unused)), char **env)
{
    char cwd[1024];
    char ***enve = malloc(sizeof(char **));
    char *testline = NULL;
    general_t *general = malloc(sizeof(general_t));

    general->actual_line = NULL;
    general->clipboard = NULL;
    general->len = 0;
    general->pos_in_hist = 0;
    general->test = 0;
    if (ac > 1)
        return 84;
    *enve = remalloc_env(env, true);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        set_env("my_bin", enve, strcat(cwd, "/42sh"), 0);
    execution(enve, NULL, testline, general);
    remalloc_env(*enve, false);
    last_free(enve, testline, general);
    return 0;
}
