/*
** EPITECH PROJECT, 2023
** my_putstrerr.c
** File description:
** my_putstrerr
*/

void my_putstrerr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_puterr(str[i]);
}
