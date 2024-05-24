/*
** EPITECH PROJECT, 2023
** my_strncmp()
** File description:
** Compares a string to another string n characters
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (n > 0 && (*s1 != '\0' || *s2 != '\0')) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}
