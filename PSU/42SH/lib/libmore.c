/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_REC
** File description:
** my_compute_power_rec.c
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int myy_strlen(char *s1)
{
    int a = 0;

    for (; s1[a]; a++);
    return a;
}

int my_strnxcmp(const char *s1, const char *s2, size_t n)
{
    size_t len1 = 0;
    size_t len2 = 0;

    while (s1[len1] != '\0') {
        len1++;
    }
    while (s2[len2] != '\0') {
        len2++;
    }
    n = (n > len1) ? len1 : n;
    n = (n > len2) ? len2 : n;
    for (size_t i = 0; i < n; i++) {
        if (s1[len1 - i - 1] != s2[len2 - i - 1]) {
            return s1[len1 - i - 1] - s2[len2 - i - 1];
        }
    }
    return 0;
}

char *my_setstringbegin(char *s1, char *s2)
{
    int len1 = myy_strlen(s1);
    int len2 = myy_strlen(s2);
    int i = 0;
    char *new = malloc(sizeof(char) * (len1 + len2 + 1));

    for (int a = 0; s1[a]; a++) {
        new[i] = s1[a];
        i++;
    }
    for (int a = 0; s2[a]; a++) {
        new[i] = s2[a];
        i++;
    }
    new[len1 + len2] = '\0';
    free(s2);
    return new;
}

char *my_setstringend(char *s1, char *s2)
{
    int len1 = myy_strlen(s1);
    int len2 = myy_strlen(s2);
    int i = 0;
    char *new = malloc(sizeof(char) * (len1 + len2 + 2));

    for (int a = 0; s1[a]; a++) {
        new[i] = s1[a];
        i++;
    }
    for (int a = 0; s2[a]; a++) {
        new[i] = s2[a];
        i++;
    }
    new[len1 + len2] = '\0';
    new[len1 + len2 + 1] = '\0';
    free(s1);
    return new;
}
