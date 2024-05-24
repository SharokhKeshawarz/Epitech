/*
** EPITECH PROJECT, 2023
** my_strchr.c
** File description:
** my_strchr
*/

#include "../../include/my.h"

char *my_strchr(const char *str, int character)
{
    while (*str != '\0') {
        if (*str == character)
            return (char *)str;
        str++;
    }
    if (character == '\0')
        return (char *)str;
    return NULL;
}
