/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** my_put_nbr.c
*/

#include <stdio.h>
#include "../include/my.h"

int my_loop(long nb, int z)
{
    if (nb < 0 && z == 0) {
        my_putchar('-');
        nb = -nb;
        z = z + 1;
    }
    if (nb / 10) {
        my_loop(nb / 10, 1);
    }
    my_putchar(nb % 10 + '0');
}

void my_put_nbr(int nb)
{
    int z = 0;
    long cc = nb;

    my_loop(cc, z);
}
