/*
** EPITECH PROJECT, 2023
** my_strninterval.c
** File description:
** my_strninterval
*/

#include "../../include/my.h"

char *my_strninterval(const char *src, int start, int end)
{
    int length = end - start;
    char *dest = (char *)malloc(length + 1);
    int j = 0;

    for (int i = start; i < end; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[length] = '\0';
    return dest;
}
