/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_SQUARE_ROOT
** File description:
** my_compute_square_root.c
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int t = 0;

    while ((t * t) < nb && nb >= 0){
        ++t;
    }
    if (nb == (t * t) && nb >= 0)
        return t;
    else
        return 0;
}
