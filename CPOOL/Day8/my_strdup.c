/*
** EPITECH PROJECT, 2023
** my_strdup()
** File description:
** Allocated memory for a string
*/

char *my_strdup(char const *str)
{
    int i = 0;
    char *result = (char *)malloc(my_strlen(str) * sizeof(char) + 1);

    my_strcpy(result, str);
    return result;
}
