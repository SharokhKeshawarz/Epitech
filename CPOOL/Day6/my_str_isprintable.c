/*
** EPITECH PROJECT, 2023
** my_str_isprintable()
** File description:
** Checks if a string contains all non printable character
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    while (str[i]) {
        if (str[i] > 32)
            i++;
        else
            return 0;
    }
    return 1;
}
