/*
** EPITECH PROJECT, 2023
** dimensions.c
** File description:
** dimensions
*/


#include "include/main.h"

void get_dimensions_2(info *newinfo, int *current, int *max, int *line)
{
    if (*line)
        *line = 0;
    else {
        (newinfo->nb_rows)++;
        if (*current > *max)
            *max = *current;
        *current = 0;
    }
}

int get_dimensions(info *newinfo)
{
    int fd = open_file(newinfo);
    int max_cols = 0;
    int current_cols = 0;
    char buffer[1];
    int firstLine = 1;

    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] == '\n')
            get_dimensions_2(newinfo, &current_cols, &max_cols, &firstLine);
        if (!firstLine && buffer[0] != '\n')
            current_cols++;
    }
    if (current_cols > 0) {
        (newinfo->nb_rows)++;
        if (current_cols > max_cols)
            max_cols = current_cols;
    }
    newinfo->nb_rows += 1;
    newinfo->nb_cols = max_cols;
    close(fd);
}
