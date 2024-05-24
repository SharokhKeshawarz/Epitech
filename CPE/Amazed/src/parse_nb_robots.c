/*
** EPITECH PROJECT, 2024
** parse_nb_robots.c
** File description:
** parse_nb_robots
*/

#include "../include/main.h"

int parse_nb_robots(file_t *file)
{
    for (int i = 0; file->array[i] != NULL; i++) {
        if (is_alldigit(file->array[i]))
            file->number_robots = my_getnbr(file->array[i]) + 1;
    }
    if (file->number_robots <= 0)
        return 84;
    return 0;
}
