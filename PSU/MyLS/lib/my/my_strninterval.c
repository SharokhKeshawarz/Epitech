/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

char *my_strninterval(const char *src, int start, int end)
{
    int length = end - start;
    char *dest = (char *)malloc(length + 1);
    int j = 0;

    for (int i = start; i < end; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[length] = '\0';
    return dest;
}
