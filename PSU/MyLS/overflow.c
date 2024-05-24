/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

long calculate_total_blocks(struct dirent **e, int n, const char *path)
{
    long total_blocks = 0;
    struct stat st;
    char full_path[1024];

    for (int i = 0; i < n; i++) {
        copy_path(full_path, path, e, i);
        lstat(full_path, &st);
        total_blocks += st.st_blocks;
    }
    return total_blocks;
}

void print_total_blocks(long total_blocks)
{
    my_printf("total %ld\n", total_blocks / 2);
}

void print_permessions(struct stat *st)
{
    my_printf((S_ISDIR(st->st_mode)) ? "d" : "-");
    my_printf((st->st_mode & S_IRUSR) ? "r" : "-");
    my_printf((st->st_mode & S_IWUSR) ? "w" : "-");
    my_printf((st->st_mode & S_IXUSR) ? "x" : "-");
    my_printf((st->st_mode & S_IRGRP) ? "r" : "-");
    my_printf((st->st_mode & S_IWGRP) ? "w" : "-");
    my_printf((st->st_mode & S_IXGRP) ? "x" : "-");
    my_printf((st->st_mode & S_IROTH) ? "r" : "-");
    my_printf((st->st_mode & S_IWOTH) ? "w" : "-");
    my_printf((st->st_mode & S_IXOTH) ? "x. " : "-. ");
}

void space(int argc, int i)
{
    if (i != argc - 1)
        my_printf("\n");
}

void print_double_dots(char **argv, int i)
{
    if (argv[i][0] == '.' || (argv[i][0] == '.' && argv[i][1] == '.'))
        my_printf("%s:\n", argv[i]);
    else
        my_printf("%s/:\n", argv[i]);
}
