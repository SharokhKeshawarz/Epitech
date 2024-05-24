/*
** EPITECH PROJECT, 2024
** gets.c
** File description:
** gets
*/

#include "asm.h"

char *create_buffer(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    ssize_t bytes_read;
    char *buffer;

    stat(path, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    bytes_read = read(fd, buffer, st.st_size);
    buffer[bytes_read] = '\0';
    return buffer;
}

char *get_name(header_t *header, char **array)
{
    char *name;

    for (int i = 0; array[i] != NULL; i++)
        if (my_strcmp(array[i], NAME_CMD_STRING) == 0) {
            name = array[i + 1];
            my_strcpy(header->prog_name, name);
        }
    return name;
}

char *get_comment(header_t *header, char **array)
{
    char *comment;

    for (int i = 0; array[i] != NULL; i++)
        if (my_strcmp(array[i], COMMENT_CMD_STRING) == 0) {
            comment = array[i + 1];
            my_strcpy(header->comment, comment);
        }
    return comment;
}

void get_size(header_t *header, char *path)
{
    header->prog_size = 0;
}
