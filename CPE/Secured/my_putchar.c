/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** my_putchar
*/

#include "include/hashtable.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
