/*
** EPITECH PROJECT, 2023
** my_strcmp()
** File description:
** Compares a string to another string
*/

int len_strcmp(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
