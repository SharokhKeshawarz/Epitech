/*
** EPITECH PROJECT, 2023
** my_strtok.c
** File description:
** Tokenize a string
*/

#include "../../include/my.h"

char *my_strtock_start(char *token, const char *limiters)
{
    char *start = token;

    while (*start != '\0' && my_strchr(limiters, *start) != NULL)
        start++;
    if (*start == '\0')
        token = NULL;
    else
        token = start;
    return token;
}

char *my_strtok(char *str, const char *limiters)
{
    static char *token = NULL;
    char *start;
    char *end;

    if (str != NULL)
        token = str;
    else if (token == NULL)
        return NULL;
    start = my_strtock_start(token, limiters);
    end = start + 1;
    while (*end != '\0' && my_strchr(limiters, *end) == NULL)
        end++;
    if (*end != '\0') {
        *end = '\0';
        token = end + 1;
    } else
        token = NULL;
    return start;
}
