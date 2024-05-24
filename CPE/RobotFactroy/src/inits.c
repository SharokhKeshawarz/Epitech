/*
** EPITECH PROJECT, 2024
** inits.c
** File description:
** inits
*/

#include "asm.h"

header_t *init_headers(char **array, char *path)
{
    header_t *header = malloc(sizeof(header_t));

    header->magic = COREWAR_EXEC_MAGIC;
    get_name(header, array);
    get_comment(header, array);
    get_size(header, path);
    return header;
}

all_t *init_all(char *buffer)
{
    all_t *all = malloc(sizeof(all_t));

    all->a = 0;
    all->array = NULL;
    all->fd = 0;
    all->binary = NULL;
    all->u = 0;
    all->x = 0;
    all->placeholder = 0;
    all->prog_size_pos = 0;
    return all;
}
