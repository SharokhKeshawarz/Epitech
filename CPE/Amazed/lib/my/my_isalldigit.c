/*
** EPITECH PROJECT, 2024
** my_isalldigit.c
** File description:
** my_isalldigit
*/

#include "../../include/my.h"

bool is_alldigit(char const *string)
{
    for (int i = 0; string[i] != '\0'; i++)
        if (!my_isdigit(string[i]))
            return false;
    return true;
}
