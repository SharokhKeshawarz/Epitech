/*
** EPITECH PROJECT, 2023
** my_put_octal.c
** File description:
** my_put_octal
*/

#include "../../include/my_printf.h"

int my_put_octal(int number)
{
    int octal[12];
    int index;
    int counter = 0;

    for (index = 0; number > 0; index++) {
        octal[index] = number % 8;
        number /= 8;
    }
    for (int i = index - 1; i >= 0; i--)
        counter += my_put_nbr(octal[i]);
    return counter;
}
