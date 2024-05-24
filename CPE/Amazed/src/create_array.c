/*
** EPITECH PROJECT, 2024
** parse.c
** File description:
** parse
*/

#include "../include/main.h"

char **create_array(void)
{
    char *line = NULL;
    size_t buffsize = 0;
    int rows = 0;
    char **array = NULL;
    ssize_t reads = getline(&line, &buffsize, stdin);

    while (reads != -1) {
        array = my_realloc(array, (rows + 1) * sizeof(char *));
        array[rows] = malloc((reads + 1) * sizeof(char));
        for (ssize_t i = 0; i < reads; i++)
            array[rows][i] = (line[i] == '\n') ? '\0' : line[i];
        array[rows][reads - 1] = '\0';
        rows++;
        reads = getline(&line, &buffsize, stdin);
    }
    array = my_realloc(array, (rows + 1) * sizeof(char *));
    array[rows] = NULL;
    return array;
}
