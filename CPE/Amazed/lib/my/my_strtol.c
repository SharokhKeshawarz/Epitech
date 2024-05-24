/*
** EPITECH PROJECT, 2023
** my_strtol.c
** File description:
** Converts a string to a long integer
*/

#include "../../include/my.h"

int my_strtol(const char *str, char **endptr)
{
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (endptr != NULL)
        *endptr = (char *)str;
    return sign * result;
}
