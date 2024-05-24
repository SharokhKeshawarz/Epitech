/*
** EPITECH PROJECT, 2024
** classic getline
** File description:
** If the program is ON with a simple echo then FIRE
*/

#include "../include/pmy.h"
#include "../include/my.h"

char *classic_getline(void)
{
    char *line;
    size_t len = 0;
    ssize_t nread = 0;

    while (1) {
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            free(line);
            return NULL;
        }
        if (line[nread - 1] == '\n') {
            line[nread - 1] = ' ';
            return line;
        }
    }
}
