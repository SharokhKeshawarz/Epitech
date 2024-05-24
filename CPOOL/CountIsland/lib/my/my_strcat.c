/*
** EPITECH PROJECT, 2023
** my_strcat()
** File description:
** Concatinates a string
*/

int strlen_cat(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int size_dest = strlen_cat(dest);
    int size_src = strlen_cat(src);

    for (int i = 0; i < size_src; i++) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + size_src] = '\0';
    return dest;
}
