/*
** EPITECH PROJECT, 2023
** my_putstr_printf.c
** File description:
** my_putstr_printf
*/

#include "../../include/my_printf.h"

int my_putstr_printf(char const *str, char character)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        counter += my_putchar(str[i]);
    return counter;
}
