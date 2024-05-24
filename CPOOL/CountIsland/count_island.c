/*
** EPITECH PROJECT, 2023
** count_island()
** File description:
** Counts the number of island in a file
*/

#include "include/my.h"

int count_rows(char **world);
int count_cols(char **world);
void x_to_number(char **world, int i, int j, char number);
void count_island_2(char **world, int i, int j, int *count);
int count_island(char **world);

int count_rows(char **world)
{
    int count = 0;

    if (world[count] == 0) {
        write(2, "ARRAY IS EMPTY", 14);
        return 0;
    }
    while (world[count] != 0)
        count++;
    return count;
}

int count_cols(char **world)
{
    if (world[0] == 0) {
        write(2, "NO ISLAND", 9);
        return 0;
    }
    return my_strlen(world[0]);
}

void x_to_number(char **world, int i, int j, char number)
{
    if (i < 0 || j < 0)
        return;
    if (i >= count_rows(world) || j >= count_cols(world))
        return;
    if (world[i][j] != 'X')
        return;
    world[i][j] = number;
    x_to_number(world, i + 1, j, number);
    x_to_number(world, i - 1, j, number);
    x_to_number(world, i, j + 1, number);
    x_to_number(world, i, j - 1, number);
}

void count_island_2(char **world, int i, int j, int *count)
{
    char countChar;

    if (world[i][j] == 'X') {
        countChar = '0' + (*count);
        x_to_number(world, i, j, countChar);
        (*count)++;
    }
}

int count_island(char **world)
{
    int rows = count_rows(world);
    int cols = count_cols(world);
    int count = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            count_island_2(world, i, j, &count);
    return count;
}
