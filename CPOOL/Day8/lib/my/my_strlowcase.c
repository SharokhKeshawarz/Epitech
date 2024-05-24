/*
** EPITECH PROJECT, 2023
** my_strlowcase()
** File description:
** Lower cases a string
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return str;
}
