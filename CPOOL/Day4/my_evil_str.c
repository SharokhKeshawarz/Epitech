/*
** EPITECH PROJECT, 2023
** my_evil_str()
** File description:
** Swaps characters
*/

char *my_evil_str(char *str)
{
    int length = 0;
    char temp;

    while (str[length])
        length++;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}
