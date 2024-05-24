/*
** EPITECH PROJECT, 2024
** my_isxdigit.c
** File description:
** my_isxdigit
*/

#include "../../include/my.h"

bool my_isxdigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'a' && c <= 'f')
        return 1;
    if (c >= 'A' && c <= 'F')
        return 1;
    return 0;
}
