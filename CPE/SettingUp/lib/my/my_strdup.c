/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** my_strdup
*/

char *my_strdup(char const *str)
{
    int length = 0;
    char *duplicate;

    while (str[length])
        length++;
    duplicate = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++)
        duplicate[i] = str[i];
    duplicate[length] = '\0';
    return duplicate;
}
