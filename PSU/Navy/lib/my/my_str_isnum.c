/*
** EPITECH PROJECT, 2023
** my_strisnum
** File description:
** Is a string only a number
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++){
        if ((str[i] >= '0' && str[i] <= '9'))
            continue;
        return (0);
    }
    return (1);
}
