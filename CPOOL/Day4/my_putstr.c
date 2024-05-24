/*
** EPITECH PROJECT, 2023
** my_putstr()
** File description:
** Displays a string
*/

int my_putstr(char const *str)
{
    while (*str) {
        my_putchar(*str);
        str++;
    }
    return 0;
}
