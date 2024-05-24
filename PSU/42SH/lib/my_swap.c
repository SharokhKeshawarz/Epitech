/*
** EPITECH PROJECT, 2023
** MY_SWAP
** File description:
** my_swap.c
*/

#include <stdio.h>

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
