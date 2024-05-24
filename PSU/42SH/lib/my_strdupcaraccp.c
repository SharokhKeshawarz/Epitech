/*
** EPITECH PROJECT, 2024
** my_strdupcaraccp
** File description:
** my_strdupcaraccp
*/

#include "../include/my.h"

char *my_strdupcaraccp(char carac, int len)
{
    char *new = malloc(sizeof(char) * (len + 1));

    for (int a = 0; a < len; a++)
        new[a] = carac;
    new[len] = '\0';
    return new;
}
