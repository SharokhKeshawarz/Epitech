/*
** EPITECH PROJECT, 2023
** my_strupcase()
** File description:
** Uppdercases a given string
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
    return str;
}
