/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** lib.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

static char *dupmyword(char word_stop, char *new, int i, char *str)
{
    int o = 0;
    int len = my_strnlen(str, '\"');

    for (; str[i]; i++) {
        if (str[i + 1] && (str[i] == '\"' && str[i + 1] == '\"') ||
        (str[i] == '\'' && str[i + 1] == '\'')){
            i++;
            continue;
        }
        if (str[i] == word_stop)
            break;
        if (str[i] == '\\')
            i++;
        new[o] = str[i];
        o++;
    }
    new[o] = '\0';
    return new;
}

int ndup(int a, char *str, int i)
{
    if (str[i] == '\"' && a == 0)
        return 1;
    if (str[i] == '\'' && a == 0)
        return 2;
    if (str[i] == '\'' && a == 2)
        return 0;
    if (str[i] == '\"' && a == 1)
        return 0;
    return a;
}

static char *my_strndup(char *str, int i, int a, char *separators)
{
    int len = my_strnlen(str, ' ');
    char *new = malloc(sizeof(char) * (len + 1));
    int o = 0;

    for (; str[i] && !((str[i] == ' ' || str[i] == '\t') && a == 0); i++) {
        if (a != ndup(a, str, i)) {
            a = ndup(a, str, i);
            continue;
        }
        len = 0;
        if (strchr(separators, str[i]) && a == 0)
            len = 95;
        if (str[i] == '\\' && a == 0)
            i++;
        new[o] = str[i] + len;
        o++;
    }
    new[o] = '\0';
    return new;
}

static int word_len(char *str)
{
    int a = 0;
    int b = 0;

    for (; str[a] && str[a] != ' ' && str[a] != '\t'; a++);
    for (; str[a + 1] != '\0' && (str[a + 1] == ' ' ||
    str[a + 1] == '\t'); a++) {
        if (str[a] == '\"')
            b++;
    }
    return a - b;
}

static int cpt_space_more(char *str, int a, char carac)
{
    int stop = 0;

    while (str[a] && str[a] != carac) {
        if (!str[a + 1]) {
            stop = 1;
            break;
        }
        a++;
    }
    if (stop == 1 && carac == '\"')
        my_perror("Unmatched \'\"\'.\n", NULL, NULL, NULL);
    if (stop == 1 && carac == '\'')
        my_perror("Unmatched \'\'\'.\n", NULL, NULL, NULL);
    if (stop == 1)
        return -1;
    return a;
}

static int cpt_space(char *str)
{
    int cpt = 1;
    int a = 0;

    for (; str[a]; a++) {
        if (a > 0 && str[a - 1] == '\\') {
            a++;
            continue;
        }
        if (str[a] == '\"')
            a = cpt_space_more(str, a + 1, '\"');
        if (str[a] == '\'')
            a = cpt_space_more(str, a + 1, '\'');
        if (a == -1)
            return 0;
        if (str[a + 1] == ' ' || str[a + 1] == '\t')
            cpt++;
        while (str[a + 1] == ' ' || str[a + 1] == '\t')
            a++;
    }
    return cpt;
}

static void transformchar_n(char *str, int cpt_word, char *new, char **argv)
{
    int len = 0;
    int b = 0;

    for (; b < cpt_word && str[0]; b++) {
        len = word_len(str);
        new = my_strndup(str, 0, 0, "<>&|;");
        argv[b] = new;
        str = &str[len + 1];
    }
    argv[b] = NULL;
}

char **mygetfree(char **argv)
{
    if (!argv)
        return NULL;
    for (int a = 0; argv[a]; a++) {
        free(argv[a]);
    }
    free(argv);
    return NULL;
}

void add_disp_command_error(line_com_t *command)
{
    if (command) {
        add_disp_command_error(command->pipe);
        add_disp_command_error(command->next);
        command->disp_com = my_strdup(command->comm[0]);
    }
}

line_com_t *transformchar(char *str, int cpt_word, history_t **historic,
    char **env)
{
    char *new = NULL;
    char **argv = NULL;

    if (!str)
        return NULL;
    while (str[0] && (str[0] == ' ' || str[0] == '\t'))
        str++;
    add_historic(historic, str);
    str = replace_backticks(str, env, 0, NULL);
    cpt_word = cpt_space(str);
    argv = malloc((cpt_word + 1) * sizeof(char *));
    transformchar_n(str, cpt_word, new, argv);
    argv = more_argv(argv, NULL);
    argv = check_rubbish(argv);
    if (argv && argv[0])
        return sort_my_old_transformchar(argv, historic, str);
    mygetfree(argv);
    return NULL;
}
