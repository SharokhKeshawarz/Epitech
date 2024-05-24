/*
** EPITECH PROJECT, 2023
** my_strcspn.c
** File description:
** my_strcspn
*/

#include "../../include/my.h"

static size_t find_reject_index(char current_char, const char *reject)
{
    size_t reject_index = 0;

    while (reject[reject_index] != '\0') {
        if (current_char == reject[reject_index])
            return reject_index;
        ++reject_index;
    }
    return reject_index;
}

size_t my_strcspn(const char *str, const char *reject)
{
    size_t length = 0;
    size_t reject_index;

    while (str[length] != '\0' && str[length] != '\n' && str[length] != '\r') {
        reject_index = find_reject_index(str[length], reject);
        if (reject[reject_index] != '\0')
            return length;
        ++length;
    }
    return length;
}
