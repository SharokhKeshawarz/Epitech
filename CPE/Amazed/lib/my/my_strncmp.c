/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n && *str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
        --n;
    }
    if (n == 0)
        return 0;
    else
        return *(unsigned char *)str1 - *(unsigned char *)str2;
}
