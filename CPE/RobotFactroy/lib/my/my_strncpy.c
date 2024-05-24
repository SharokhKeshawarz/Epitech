/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Copy's a string n characters
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, const char *src, unsigned long n)
{
    char *d = dest;
    const char *s = src;

    while (n > 0 && *s != '\0') {
        *d = *s;
        d++;
        s++;
        n--;
    }
    while (n > 0) {
        *d = '\0';
        d++;
        n--;
    }
    return dest;
}
