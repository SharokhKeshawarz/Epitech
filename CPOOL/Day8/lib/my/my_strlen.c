/*
** EPITECH PROJECT, 2023
** my_strlen()
** File description:
** returns length of a function
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return length;
}
