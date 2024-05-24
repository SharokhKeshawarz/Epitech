/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "include/hashtable.h"

static void check_conditions(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (nb < 0)
        my_putchar('-');
}

int my_put_nbr(int nb)
{
    long number = nb;
    long reverse = 1;
    long digit = 0;

    check_conditions(nb);
    if (nb < 0)
        number *= -1;
    while (number > 0) {
        digit = number % 10;
        reverse = (reverse * 10) + digit;
        number /= 10;
    }
    while (reverse > 1) {
        digit = reverse % 10;
        my_putchar(digit + 48);
        reverse /= 10;
    }
    return 0;
}
