/*
** EPITECH PROJECT, 2023
** my_strncpy()
** File description:
** Copies a string to another string n characters
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int length = 0;

    while (src[length])
        length++;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > length)
        dest[i] = '\0';
    return dest;
}
