/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** delimite commands
*/

#include "../include/pmy.h"
#include "../include/my.h"

static char *pid_child_for_backticks(char *exe, int *pipefd)
{
    dup2(pipefd[0], STDIN_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    execlp(exe, exe, NULL);
    my_perror("Execlp : binary 42sh not executed\n", NULL, NULL, NULL);
    exit(EXIT_FAILURE);
}

char *extract_backticks(char *command, char **env, char *exe, pid_t pid)
{
    int pipefd[2];
    char buffer[100];

    if (pipe(pipefd) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit(EXIT_FAILURE);
    if (pid == 0) {
        pid_child_for_backticks(exe, pipefd);
    } else {
        write(pipefd[1], command, strlen(command));
        write(pipefd[1], "\n", 1);
        write(pipefd[1], "exit\n", 5);
        close(pipefd[1]);
        wait(NULL);
        if (read(pipefd[0], buffer, sizeof(buffer)) == -1)
            exit(EXIT_FAILURE);
    }
    return my_strdup(buffer);
}

static char *my_notfreesetstringbegin(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int i = 0;
    char *new = malloc(sizeof(char) * (len1 + len2 + 1));

    if (new == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int a = 0; s1[a] != '\0'; a++) {
        new[i] = s1[a];
        i++;
    }
    for (int a = 0; s2[a] != '\0'; a++) {
        new[i] = s2[a];
        i++;
    }
    new[len1 + len2] = '\0';
    return new;
}

static void multi_strcat(char *temp, const char *replacement, char *end)
{
    strcat(temp, replacement);
    strcat(temp, end + 1);
}

static char *replace_backticks_in_str(char *input, const char *replacement,
    char *result, char *end)
{
    char *start = input;
    char *temp = NULL;

    start = strchr(start, '`');
    while (start != NULL) {
        end = strchr(start + 1, '`');
        if (end == NULL)
            break;
        temp = malloc(sizeof(char) * (strlen(input) -
        (end - start - 1) + strlen(replacement) + 1));
        strncpy(temp, input, start - input);
        temp[start - input] = '\0';
        multi_strcat(temp, replacement, end);
        result = temp;
        start = end + strlen(replacement) + 1;
        start = strchr(start, '`');
    }
    if (result == NULL)
        result = strdup(input);
    return result;
}

static char *contain_backt(char *str)
{
    int a = 0;
    int b = 0;

    for (; str[a] && (str[a] != '`' || (a > 0 && str[a - 1] == '\\')); a++);
    if (str[a] == '`') {
        for (b = a + 1; str[b] && (str[b] != '`' || str[b - 1] == '\\'); b++);
        if (b - a - 1 <= 0 || !str[b])
            return NULL;
        return my_strduplen(&str[a + 1], b - a - 1);
    }
    return NULL;
}

char *find_inenv(char **env)
{
    char *new = NULL;
    int a = 0;

    for (; env[a] && my_strncmp(env[a], "my_bin=", 6) != 0; a++);
    if (env[a] == NULL) {
        my_perror("env : address of binary 42sh deleted\n", NULL, NULL, NULL);
        return NULL;
    }
    return &env[a][7];
}

char *replace_backticks(char *str, char **env, int count, char *new)
{
    char *exe = find_inenv(env);

    if (!exe)
        return NULL;
    for (int a = 0; str[a]; a++)
        if (str[a] == '`')
            count++;
    if (count % 2 == 1) {
        str[0] = '\0';
        my_perror("Unmatched '`'.\n", NULL, NULL, NULL);
        return str;
    }
    new = contain_backt(str);
    while (new) {
        new = extract_backticks(new, NULL, exe, 0);
        str = replace_backticks_in_str(str, new, NULL, NULL);
        new = contain_backt(str);
    }
    return str;
}
