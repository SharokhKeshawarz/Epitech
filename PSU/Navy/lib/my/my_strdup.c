/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** Allocates and copy's a string to a char *
*/

#include "../../include/my.h"

char *my_strdup(const char *str)
{
    int length = 0;
    char *duplicate;

    while (str[length])
        length++;
    duplicate = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++)
        duplicate[i] = str[i];
    duplicate[length] = '\0';
    return duplicate;
}
