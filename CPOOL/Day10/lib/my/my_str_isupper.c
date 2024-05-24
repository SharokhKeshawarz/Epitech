/*
** EPITECH PROJECT, 2023
** my_str_isupper()
** File description:
** Checks if the string is upper case
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    while (str[i]) {
        if (str[i] >= 65 && str[i] <= 90)
            i++;
        else
            return 0;
    }
    return 1;
}
