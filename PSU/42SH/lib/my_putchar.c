/*
** EPITECH PROJECT, 2023
** test
** File description:
** my_putchar.c
*/

#include <stdio.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchart(char *c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        ++i;
    }
}
