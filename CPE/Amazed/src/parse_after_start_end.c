/*
** EPITECH PROJECT, 2024
** parse_rooms.c
** File description:
** parse_rooms
*/

#include "../include/main.h"

void parse_start_end(file_t *file)
{
    for (int i = 0; file->array[i] != NULL; i++) {
        if (my_strcmp("##start", file->array[i]) == 0)
            file->start = my_strdup(file->array[i + 1]);
        if (my_strcmp("##end", file->array[i]) == 0)
            file->end = my_strdup(file->array[i + 1]);
    }
}
