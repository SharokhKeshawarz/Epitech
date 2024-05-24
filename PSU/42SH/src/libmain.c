/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** lib.c
*/

#include "../include/pmy.h"
#include "../include/my.h"

void my_strcpy(char *dest, const char *src)
{
    int a = 0;

    for (; src[a]; a++)
        dest[a] = src[a];
    dest[a] = '\0';
}

bool find_letter(const char *s, const char letter)
{
    for (int a = 0; s[a]; a++)
        if (s[a] == letter)
            return true;
    return false;
}

void my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    for (; src[a] && a < n; a++)
        dest[a] = src[a];
    dest[a] = '\0';
}

char *my_strduplen(char *str, int len)
{
    char *new = malloc(sizeof(char) * (len + 1));
    int o = 0;

    for (; str[o] && o < len; o++)
        new[o] = str[o];
    new[o] = '\0';
    new[len] = '\0';
    return new;
}

int my_strnlen(char *str, char carac)
{
    int a = 0;

    if (carac != ' ') {
        for (; str[a] && str[a] != carac; a++);
        return a;
    }
    for (; str[a] && str[a] != carac && str[a] != '\t'; a++);
    return a;
}
