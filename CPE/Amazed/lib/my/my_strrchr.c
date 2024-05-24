/*
** EPITECH PROJECT, 2023
** my_strrchr.c
** File description:
** my_strrchr
*/

#include "../../include/my.h"

char *my_strrchr(const char *str, int ch)
{
    const char *last_occurrence = NULL;

    while (*str != '\0') {
        if (*str == ch)
            last_occurrence = str;
        str++;
    }
    return (char *)last_occurrence;
}
