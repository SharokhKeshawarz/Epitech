/*
** EPITECH PROJECT, 2024
** extract_number.c
** File description:
** extract_number
*/

#include "../../include/my.h"

static void my_get_nbr_2(int *result, int *max_digits, int *current_digits)
{
    if (*current_digits > *result) {
        (*result) = (*current_digits);
        (*max_digits) = (*current_digits);
    }
}

int my_get_nbr(const char *str)
{
    int result = 0;
    int max_digits = 0;
    int current_digits = 0;

    while (*str) {
        if (my_isdigit(*str)) {
            current_digits = current_digits * 10 + (*str - '0');
            my_get_nbr_2(&result, &max_digits, &current_digits);
        } else
            current_digits = 0;
        str++;
    }
    return result;
}
