/*
** EPITECH PROJECT, 2023
** my_realloc.c
** File description:
** my_realloc
*/

#include "../../include/my.h"

void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr = malloc(new_size);
    char *old_ptr;
    char *new_ptr_char;

    if (new_ptr == NULL)
        exit(EXIT_FAILURE);
    if (ptr != NULL) {
        old_ptr = (char *)ptr;
        new_ptr_char = (char *)new_ptr;
        for (size_t i = 0; i < old_size; i++)
            new_ptr_char[i] = old_ptr[i];
        free(ptr);
    }
    return new_ptr;
}
