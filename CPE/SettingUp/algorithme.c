/*
** EPITECH PROJECT, 2023
** algorithme.c
** File description:
** algorithme
*/

#include "include/main.h"

static void find_biggest_square_2(info *newinfo, int i, int *quit, int size)
{
    int row = newinfo->row;
    int col = newinfo->col;

    for (int j = col; (j < col + size) && *quit != 1; j++) {
        if (newinfo->map[i][j] == 'o') {
            *quit = 1;
            return;
        }
    }
}

int find_biggest_square(info *newinfo)
{
    int maxSize = 0;
    int s;
    int row = newinfo->row;
    int col = newinfo->col;
    int nrow = newinfo->nb_rows;
    int ncol = newinfo->nb_cols;
    int quit = 0;

    for (s = 0; (row + s <= nrow && col + s <= ncol) && quit != 1; s++) {
        for (int i = row; (i < row + s) && quit != 1; i++)
            find_biggest_square_2(newinfo, i, &quit, s);
        if (quit == 1)
            return maxSize;
        maxSize = s;
    }
    if (quit == 1)
        return maxSize;
    return maxSize;
}

void replace_biggest_square(info *newinfo)
{
    int maxrow = newinfo->max_row;
    int maxcol = newinfo->max_col;
    int maxsize = newinfo->max_size;

    for (int i = maxrow; i < maxrow + maxsize; i++)
        for (int j = maxcol; j < maxcol + maxsize; j++)
            newinfo->map[i][j] = 'x';
}
