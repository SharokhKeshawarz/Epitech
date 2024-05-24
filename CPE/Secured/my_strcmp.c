/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "include/hashtable.h"

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}
