/*
** EPITECH PROJECT, 2024
** my_isdigit.c
** File description:
** my_isdigit
*/

#include "../../include/my.h"

int my_isdigit(char character)
{
    if (character >= 48 && character <= 57)
        return 1;
    return 0;
}
