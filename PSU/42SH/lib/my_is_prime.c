/*
** EPITECH PROJECT, 2023
** MY_IS_PRIME
** File description:
** my_is_prime.c
*/

#include <stdio.h>

long my_prime(long nb)
{
    long t = nb - 1;

    while (t > 1){
        if ((nb % t) == 0)
            return 0;
        else
            --t;
    }
    return 1;
}

int my_is_prime(int nb)
{
    long n = nb;

    if (nb <= 1)
        return 0;
    return my_prime(n);
}
