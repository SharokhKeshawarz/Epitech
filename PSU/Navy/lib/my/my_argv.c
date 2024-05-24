/*
** EPITECH PROJECT, 2023
** my_argv.c
** File description:
** my_argv
*/

#include "../../include/my.h"

void free_argv_array(char **array, int argc)
{
    for (int i = 0; i < argc; i++)
        free(array[i]);
    free(array);
}

char **my_argv_to_array(int argc, char **argv)
{
    char **array = malloc(argc * sizeof(char *));

    for (int i = 0; i < argc; i++)
        array[i] = my_strdup(argv[i]);
    return array;
}
