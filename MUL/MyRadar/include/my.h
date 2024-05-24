/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <stdlib.h>


char *my_strdup(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strninterval(const char *src, int start, int end);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcasecmp(const char *s1, const char *s2);
int my_tolower(char c);
char *my_strtok(char *str, const char *delimiters);
char *my_strchr(const char *str, int character);
int my_atoi(const char *str);
int my_strcmp(const char *str1, const char *str2);
int my_strtol(const char *str, char **endptr);
char *my_strncpy(char *dest, const char *src, unsigned long n);
int extract_numbers(const char *str, int *numbers, int max_numbers);
void its(int number, char *result);

#endif
