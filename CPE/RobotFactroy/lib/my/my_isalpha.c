/*
** EPITECH PROJECT, 2024
** my_isalpha.c
** File description:
** my_isalpha
*/

#include "../../include/my.h"

int my_isalpha(char character)
{
    if (character >= 'a' && character <= 'z')
        return 1;
    else if (character >= 'A' && character <= 'Z')
        return 1;
    else
        return 0;
}
