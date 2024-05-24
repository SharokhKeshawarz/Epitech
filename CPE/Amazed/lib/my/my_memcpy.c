/*
** EPITECH PROJECT, 2023
** my_its.c
** File description:
** Integer to string of numbers
*/

#include "../../include/my.h"

void my_memcpy(void *dest, const void *src, size_t n)
{
    char *dest_char = (char *)dest;
    const char *src_char = src;

    for (size_t i = 0; i < n; i++)
        dest_char[i] = src_char[i];
}
