/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** my_putchar
*/

#include "../../include/my_printf.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
