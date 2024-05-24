/*
** EPITECH PROJECT, 2023
** my_strncat()
** File description:
** Concatinates n string
*/

int strlen_catn(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_dest = strlen_catn(dest);
    int size_src = strlen_catn(src);
    int i = 0;

    for (i = 0; i < size_src && i < nb; i++) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + i] = '\0';
    return dest;
}
