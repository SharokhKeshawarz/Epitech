/*
** EPITECH PROJECT, 2023
** my_put_hex.c
** File description:
** my_put_hex
*/

#include "../../include/my_printf.h"

static void hex_value(char hex[10], int index, int remainder, char character)
{
    if (character == 'X') {
        if (remainder < 10)
            hex[index] = remainder + 48;
        else
            hex[index] = remainder - 10 + 65;
    } else {
        if (remainder < 10)
            hex[index] = remainder + 48;
        else
            hex[index] = remainder - 10 + 97;
    }
}

int my_put_hex(int number, char character)
{
    char hex[10];
    int index;
    int counter = 0;
    int remainder = 0;

    for (index = 0; number > 0; index++) {
        remainder = number % 16;
        hex_value(hex, index, remainder, character);
        number /= 16;
    }
    for (int i = index - 1; i >= 0; i--)
        counter += my_putchar(hex[i]);
    return counter;
}
