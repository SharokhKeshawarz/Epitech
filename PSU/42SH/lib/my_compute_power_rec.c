/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_REC
** File description:
** my_compute_power_rec.c
*/

#include <stdio.h>

long my_pow_rec(long n, int p)
{
    if (p == 0) {
        return 1;
    } else {
        return n * my_pow_rec(n, p - 1);
    }
}

int my_compute_power_rec(int nb, int p)
{
    long n = nb;

    if (p < 0) {
        return 0;
    }
    return my_pow_rec(n, p);
}
