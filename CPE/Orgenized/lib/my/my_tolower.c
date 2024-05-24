/*
** EPITECH PROJECT, 2023
** my_tolower.c
** File description:
** my_tolower
*/

int my_tolower(char c)
{
    if (c >= 65 && c <= 90)
        return c + (97 - 65);
    else
        return c;
}
