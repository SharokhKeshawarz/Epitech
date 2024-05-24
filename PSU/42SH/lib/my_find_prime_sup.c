/*
** EPITECH PROJECT, 2023
** MY_FIND_PRIME_SUP
** File description:
** my_find_prime_sup.c
*/

#include <stdio.h>

long my_prime_sup(long nb)
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

int my_find_prime_sup(int nb)
{
    long n = nb;

    if (nb == 1 || nb == 0)
        return 2;
    if (my_prime_sup(n) == 1)
        return nb;
    else
        return my_find_prime_sup(nb + 1);
}
