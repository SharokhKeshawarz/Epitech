/*
** EPITECH PROJECT, 2023
** inits.c
** File description:
** inits
*/

#include "../include/proto.h"

file_t *init_file_struct(char *path)
{
    file_t *file = malloc(sizeof(file_t));

    file->fd = NULL;
    file->path = my_strdup(path);
    file->size = 0;
    file->array = NULL;
    file->string = NULL;
    return file;
}

info_t *init_info_struct(int argc, char **argv)
{
    info_t *info = malloc(sizeof(info_t));

    info->pid = 0;
    info->argc = argc;
    info->argv = my_argv_to_array(info->argc, argv);
    return info;
}

void destroy(info_t *info, file_t *file)
{
    free(file->string);
    for (int i = 0; file->array[i] != 0; i++)
        free(file->array[i]);
    free(file->array);
    free(file);
    free_argv_array(info->argv, info->argc);
    free(info);
}
