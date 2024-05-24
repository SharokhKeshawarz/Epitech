/*
** EPITECH PROJECT, 2023
** my_strcasecmp.c
** File description:
** Compare cases of characters
*/

#include "../../include/my.h"

int my_strcasecmp(const char *s1, const char *s2)
{
    int diff = 0;

    while (*s1 != '\0' && *s2 != '\0') {
        diff = my_tolower((unsigned char)*s1) - my_tolower((unsigned char)*s2);
        if (diff != 0)
            return diff;
        s1++;
        s2++;
    }
    return my_tolower((unsigned char)*s1) - my_tolower((unsigned char)*s2);
}
