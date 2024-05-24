/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "include/main.h"

info *init_info(void)
{
    info *new_info = malloc(sizeof(info));

    new_info->map = NULL;
    new_info->filepath = NULL;
    new_info->buffer = NULL;
    new_info->nb_rows = 0;
    new_info->nb_cols = 0;
    new_info->max_row = 0;
    new_info->max_col = 0;
    new_info->max_size = 0;
    new_info->row = 0;
    new_info->col = 0;
    return new_info;
}

void print_2d_arr(info *newinfo)
{
    for (int i = 0; i < newinfo->nb_rows - 1; i++) {
        for (int j = 0; j < newinfo->nb_cols; j++) {
            my_putchar(newinfo->map[i][j]);
        }
        my_putchar('\n');
    }
}

static void set_size(info *newinfo, int i, int j)
{
    int size = 0;
    int max = newinfo->max_size;
    int mcol = newinfo->max_col;

    if (newinfo->map[i][j] == '.') {
        newinfo->row = i;
        newinfo->col = j;
        size = find_biggest_square(newinfo);
        if (size > max || (size == max && j < mcol)) {
            newinfo->max_size = size;
            newinfo->max_row = i;
            newinfo->max_col = j;
        }
    }
}

static void algo(info *newinfo)
{
    for (int i = 0; i < newinfo->nb_rows; i++)
        for (int j = 0; j < newinfo->nb_cols; j++)
            set_size(newinfo, i, j);
}

static void destroy(info *newinfo)
{
    free(newinfo->filepath);
    free(newinfo->buffer);
    for (int i = 0; i < newinfo->nb_rows; i++)
        free(newinfo->map[i]);
    free(newinfo->map);
    free(newinfo);
}

static int file_operations(info *newinfo, char **argv)
{
    struct stat st;

    if (stat(argv[1], &st) == -1) {
        my_putstrerr("File Dosent Existe\n");
        return 84;
    }
    if (S_ISDIR(st.st_mode)) {
        my_putstrerr("Argument Must Be A File\n");
        return 84;
    }
    if (get_dimensions(newinfo) == 84)
        return 84;
    if (load_file_in_mem(newinfo) == 84) {
        my_putstrerr("File Empty");
        return 84;
    }
}

static int arguments_checker(int argc, char **argv)
{
    if (argc == 1 || argv[1] == NULL) {
        my_putstrerr("Usage: (executable) <file>\n");
        return 84;
    }
}

int main(int argc, char **argv)
{
    info *newinfo = init_info();

    if (arguments_checker(argc, argv) == 84)
        return 84;
    newinfo->filepath = my_strdup(argv[1]);
    if (file_operations(newinfo, argv) == 84)
        return 84;
    if (load_2d_arr_from_file(newinfo) == 84)
        return 84;
    algo(newinfo);
    replace_biggest_square(newinfo);
    print_2d_arr(newinfo);
    destroy(newinfo);
    return 0;
}
