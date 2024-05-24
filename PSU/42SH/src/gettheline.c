/*
** EPITECH PROJECT, 2024
** gettheline
** File description:
** Hello ! It's me your, trust-worthy companion. Ask me whatever you want !
*/

#include "../include/pmy.h"
#include "../include/my.h"

char *gettheline(char *exe, char *mem,
    general_t *general, history_t **historic)
{
    int i = 0;
    line_edit_t *edition = malloc(sizeof(line_edit_t));
    char *tmp;

    if (isatty(0)) {
        tmp = line_edit(edition, general, historic);
    } else
        tmp = classic_getline();
    if (tmp == NULL)
        exit(general->test);
    exe = malloc(sizeof(char) * (strlen(tmp) + 2));
    exe = strcpy(exe, tmp);
    free(tmp);
    free(edition);
    for (; exe[i] && exe[i] != '\n'; i++);
    if (exe[i] != '\0')
        if (general->test != -1)
            exit(general->test);
    return exe;
}
