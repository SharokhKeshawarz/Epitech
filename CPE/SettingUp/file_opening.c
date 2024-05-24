/*
** EPITECH PROJECT, 2023
** file_opening.c
** File description:
** file_opening
*/

#include "include/main.h"

int open_file(info *newinfo)
{
    int fd = open(newinfo->filepath, O_RDONLY);

    if (fd == -1) {
        my_putstrerr("File Not Found\n");
        return 84;
    }
    return fd;
}

static int get_nb(info *newinfo, int *number)
{
    if (newinfo->nb_rows == 0 || newinfo->nb_rows == 1)
        return 84;
    for (int i = 0; newinfo->buffer[i] != '\n'; i++)
        (*number) = ((*number) * 10) + newinfo->buffer[i] - 48;
    if (newinfo->nb_rows - 1 != *number) {
        my_putstrerr("Row and Cols are not the same\n");
        return 84;
    }
    return 0;
}

int load_file_in_mem(info *newinfo)
{
    int fd = open_file(newinfo);
    struct stat st;
    ssize_t bytesRead;
    int number = 0;

    stat(newinfo->filepath, &st);
    newinfo->buffer = (char *)malloc(st.st_size + 1);
    bytesRead = read(fd, newinfo->buffer, st.st_size);
    newinfo->buffer[bytesRead] = '\0';
    close(fd);
    if (bytesRead == 0 || get_nb(newinfo, &number) == 84)
        return 84;
    for (int i = 0; newinfo->buffer[i] != '\0'; i++) {
        if (newinfo->buffer[i] == 'x') {
            my_putstrerr("x already present in the file\n");
            return 84;
        }
    }
    return 0;
}

static int check_error_char(info *newinfo, int i, int j)
{
    if (newinfo->map[i][j] != '\n' && newinfo->map[i][j] != '\0') {
        if (newinfo->map[i][j] != '.' && newinfo->map[i][j] != 'o')
            return 84;
        else
            return 0;
    }
}

static int error_loop(info *newinfo, int *error)
{
    for (int i = 0; i < newinfo->nb_rows - 1; i++)
        for (int j = 0; j < newinfo->nb_cols; j++)
            *error += check_error_char(newinfo, i, j);
}

static void load_2d_arr_from_file_3(info *newinfo, int *pos)
{
    while (newinfo->buffer[*pos] != '\n' && newinfo->buffer[*pos] != '\0') {
        (*pos)++;
    }
}

static void load_2d_arr_from_file_2(info *newinfo, int *pos)
{
    while (newinfo->buffer[*pos] == '\n')
        (*pos)++;
}

int load_2d_arr_from_file(info *newinfo)
{
    int pos = 0;
    int error = 0;

    newinfo->map = (char **)malloc(newinfo->nb_rows * sizeof(char *));
    for (int i = 0; i < newinfo->nb_rows; i++) {
        newinfo->map[i] = malloc((newinfo->nb_cols + 1) * sizeof(char));
        load_2d_arr_from_file_3(newinfo, &pos);
        for (int j = 0; j < newinfo->nb_cols; j++) {
            load_2d_arr_from_file_2(newinfo, &pos);
            newinfo->map[i][j] = newinfo->buffer[pos];
            pos++;
        }
        newinfo->map[i][newinfo->nb_cols] = '\0';
    }
    error_loop(newinfo, &error);
    if (error > 0) {
        my_putstrerr("Another Character Present Than o and .\n");
        return 84;
    }
    return 0;
}
