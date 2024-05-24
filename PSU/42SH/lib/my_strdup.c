/*
** EPITECH PROJECT, 2023
** MY_STRUPCASE
** File description:
** my_strupcase.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));

    if (!new)
        return NULL;
    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    new[len] = '\0';
    return new;
}
