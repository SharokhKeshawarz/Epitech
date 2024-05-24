/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Prints a character
*/

int my_putchar(char c)
{
    write(1, &c, 1);
}
