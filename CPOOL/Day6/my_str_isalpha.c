/*
** EPITECH PROJECT, 2023
** my_str_isalpha()
** File description:
** Checks if a string contaiains number
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    while (str[i]) {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
            i++;
        else
            return 0;
    }
    return 1;
}
