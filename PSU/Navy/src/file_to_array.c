/*
** EPITECH PROJECT, 2023
** file_to_array.c
** File description:
** file_to_array
*/

#include "../include/proto.h"

static int open_file(file_t *file)
{
    file->fd = fopen(file->path, "r");
    if (file->fd == NULL)
        return 84;
    return 0;
}

static int size_file(file_t *file)
{
    char *buffer = NULL;
    int length = 0;

    if (file->fd == NULL)
        return 84;
    while (getline(&buffer, &length, file->fd) > 0)
        file->size += my_strlen(buffer);
    free(buffer);
    return 0;
}

static int create_str_boats(file_t *file)
{
    char *buffer = NULL;
    int length = 0;

    file->string = malloc(sizeof(char) * file->size + 1);
    if (file->fd == NULL || file->size == 0 || file->string == NULL)
        return 84;
    fseek(file->fd, 0, SEEK_SET);
    while (getline(&buffer, &length, file->fd) > 0)
        file->string = my_strcat(file->string, buffer);
    file->string[file->size] = '\0';
    free(buffer);
    fclose(file->fd);
    free(file->path);
    return 0;
}

static int create_tab_boats(file_t *file)
{
    int i;

    file->array = my_str_to_word_array(file->string);
    if (column_checker(file) == 84)
        return 84;
    if (error_handling_files(file) == 84)
        return 84;
    for (i = 0; file->array[i] != NULL; i++);
    if (i < 4)
        return 84;
    return 0;
}

int init_file_struct_values(file_t *file)
{
    if (open_file(file) == 84)
        return 84;
    if (size_file(file) == 84)
        return 84;
    if (create_str_boats(file) == 84)
        return 84;
    if (create_tab_boats(file) == 84)
        return 84;
    return 0;
}
