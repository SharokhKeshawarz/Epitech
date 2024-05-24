/*
** EPITECH PROJECT, 2023
** my_str_islower()
** File description:
** Checks if a string is only lower case
*/

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    while (str[i]) {
        if (str[i] >= 97 && str[i] <= 122)
            i++;
        else
            return 0;
    }
    return 1;
}
