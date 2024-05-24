/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

int my_tolower(int c)
{
    if (c >= 65 && c <= 90)
        return c + (97 - 65);
    else
        return c;
}
