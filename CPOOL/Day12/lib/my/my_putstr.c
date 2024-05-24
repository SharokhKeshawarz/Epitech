/*
** EPITECH PROJECT, 2023
** my_putstr()
** File description:
** Displays a string
*/

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
