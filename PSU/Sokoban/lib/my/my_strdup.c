/*
** EPITECH PROJECT, 2023
** my_strdup()
** File description:
** Copies a string content to another string
*/

char *my_strdup(const char *str)
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
