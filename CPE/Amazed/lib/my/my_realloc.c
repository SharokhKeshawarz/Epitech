/*
** EPITECH PROJECT, 2023
** my_realloc.c
** File description:
** my_realloc
*/

#include "../../include/my.h"

void *my_realloc(void *ptr, size_t new_size)
{
    void *new_ptr;

    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;
    my_memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}
