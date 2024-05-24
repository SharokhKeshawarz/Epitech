/*
** EPITECH PROJECT, 2024
** exclamation.c
** File description:
** exclamation
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

static char *first_string(char *exe)
{
    char *executable = (char *)malloc(strlen(exe) + 1);

    if (executable == NULL)
        exit(84);
    for (int i = 0; exe[i] != '\0'; i++) {
        if (exe[i] != ' ' && exe[i] != '\n') {
            executable[i] = exe[i];
        } else {
            executable[i] = '\0';
            break;
        }
    }
    return executable;
}

static char *sec_string(char *exe)
{
    char *executable = (char *)malloc(strlen(exe) + 1);
    int i = 0;
    int j = 0;

    if (executable == NULL)
        exit(84);
    for (i = 0; exe[i] != '\0' && exe[i] != ' '; i++);
    if (exe[i] == ' ') {
        for (j = 0; exe[i] != '\0'; i++){
            executable[j] = exe[i];
            j++;
        }
        executable[j] = '\0';
    } else
        strcat(executable, exe);
    return executable;
}

int voir_si_car(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' ')
            return 0;
    }
    return 1;
}

static char *exe_cpy(char *executable, char *sec, char *sec_cur)
{
    if (sec_cur != NULL && voir_si_car(sec_cur) == 0){
        remove_extra_spaces(sec_cur);
        strncat(executable, sec_cur, strlen(sec_cur));
    }
    if (sec != NULL && voir_si_car(sec) == 0){
        remove_extra_spaces(sec);
        strncat(executable, sec, strlen(sec));
    }
    strcat(executable, " ");
    return executable;
}

static void exclam_espace(int *a, char *executable)
{
    if (*a == 0){
        strcat(executable, " ");
        *a = 1;
    }
}

char *history_exclamtion_r(history_t **history, char *exes)
{
    history_t *current = *history;
    char *executable = first_string(exes);
    char *sec = sec_string(exes);
    char *sec_cur = sec_string(current->line_com);
    int a = 0;

    while (current != NULL) {
        sec_cur = sec_string(current->line_com);
        exclam_espace(&a, executable);
        if (my_strncmp(executable, current->line_com,
        strlen(executable)) == 0){
            executable = exe_cpy(executable, sec, sec_cur);
            free(sec);
            return executable;
        }
        current = current->next;
    }
    free(sec);
    return executable;
}

static void extra_space_suite(int *inside_word, char carac, char *str, int *j)
{
    if (carac != ' ') {
        str[*j] = carac;
        (*j)++;
        *inside_word = 1;
    } else {
        if (*inside_word) {
            str[*j] = carac;
            (*j)++;
            *inside_word = 0;
        }
    }
}

void remove_extra_spaces(char *str)
{
    int j = 0;
    int inside_word = 0;

    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++)
        extra_space_suite(&inside_word, str[i], str, &j);
    str[j] = '\0';
}

static char *history_exclamtion_r_s(history_t **history, char *exes)
{
    history_t *current = *history;

    while (current != NULL){
        if (current->nb == atoi(exes))
            return current->line_com;
        current = current->next;
    }
    return NULL;
}

char *history_exclamtion(char *exe, history_t **history)
{
    char *exes = NULL;

    if (exe[0] == '!') {
        if (!isdigit(exe[1])) {
            exes = exe + 1;
            exes = history_exclamtion_r(history, exes);
            remove_extra_spaces(exes);
            printf("%s\n", exes);
            return exes;
        } else {
            exes = exe + 1;
            exes = history_exclamtion_r_s(history, exes);
            remove_extra_spaces(exes);
            printf("%s\n", exes);
            return exes;
        }
    }
    return exe;
}
