/*
** EPITECH PROJECT, 2023
** my_puterr.c
** File description:
** my_puterr
*/

void my_puterr(char c)
{
    write(2, &c, 1);
}
