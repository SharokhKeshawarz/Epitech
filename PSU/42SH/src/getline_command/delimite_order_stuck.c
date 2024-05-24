/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** delimite commands
*/

#include "../include/pmy.h"
#include "../include/my.h"

int *create_var_int(int f, int s, int t)
{
    int *first_count = malloc(sizeof(int) * 3);

    first_count[0] = f;
    first_count[1] = s;
    first_count[2] = t;
    return first_count;
}

int send_in_new_argv(char **new, int count, char *argva, int b)
{
    int *first_count = create_var_int(0, count, 0);

    for (int error = 0; argva[b]; b++) {
        first_count[2] = 0;
        if (my_strchr(argva[b], "<>&|;") == 2)
            error = have_a_delimiter(first_count, b, argva, new);
        if (error == -1) {
            free(first_count);
            return -84;
        }
        b += (first_count[2] != 0) ? first_count[2] - 1 : 0;
        first_count[0] += (first_count[2] > 1) ? first_count[2] - 1 : 0;
    }
    if (first_count[0] != b) {
        new[first_count[1]] = my_strdup(&argva[first_count[0]]);
        first_count[1]++;
    }
    count = first_count[1];
    free(first_count);
    return count;
}

char **please_malloc(int max)
{
    char **new = malloc(sizeof(char *) * (max + 1));

    for (int a = 0; a < max; a++)
        new[a] = NULL;
    return new;
}

static void resize_char_d(char **argv, int a)
{
    free(argv[a]);
    for (; argv[a + 1]; a++)
        argv[a] = argv[a + 1];
    argv[a] = NULL;
}

static char **check_rubbish_last(char **argv)
{
    int last = 0;

    for (; argv[last + 1]; last++);
    while (argv[last] && last > 0) {
        if (my_strchr(argv[last][0], ";") == 2) {
            resize_char_d(argv, last);
            last--;
            continue;
        }
        if (my_strchr(argv[last][0], "|&") == 2) {
            my_printf("Invalid null argument\n");
            return mygetfree(argv);
        }
        break;
    }
    return argv;
}

static char **correct_argv(char **argv)
{
    int ez = 0;
    int b = 0;
    char carac = 0x01;

    for (int a = 0; argv[a]; a++) {
        b = 0;
        for (; argv[a][b] && my_strchr(argv[a][b], "|&;<>"); b++)
            argv[a][b] -= 95;
        if (b == my_strlen(argv[a]))
            argv[a] = my_setstringbegin(&carac, argv[a]);
    }
    for (int a = 0; argv[a]; a++) {
        ez = argv[a][0];
        if (ez == 0 || (ez == 1 && argv[a][1] == '\0'))
            resize_char_d(argv, a);
    }
    return argv;
}

char **check_rubbish(char **argv)
{
    while (argv && argv[0] && argv[1]) {
        if (my_strchr(argv[0][0], ";") == 2) {
            resize_char_d(argv, 0);
            continue;
        }
        if (my_strchr(argv[0][0], "|") == 2) {
            my_printf("Invalid null argument\n");
            return mygetfree(argv);
        }
        if (my_strchr(argv[0][0], "&") == 2) {
            resize_char_d(argv, 0);
            continue;
        }
        break;
    }
    if (!argv || check_rubbish_last(argv) == NULL)
        return NULL;
    return correct_argv(argv);
}

line_com_t *sort_my_old_transformchar(char **argv, history_t **historic,
    char *str)
{
    line_com_t *new_t = NULL;

    new_t = magicinputoutput(argv);
    add_disp_command_error(new_t);
    mygetfree(argv);
    return new_t;
}
