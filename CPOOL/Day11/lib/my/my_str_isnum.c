/*
** EPITECH PROJECT, 2023
** my_str_isnum()
** File description:
** Checks if a string contains only number
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    while (str[i]) {
        if (str[i] >= 48 && str[i] <= 57)
            i++;
        else
            return 0;
    }
    return 1;
}
