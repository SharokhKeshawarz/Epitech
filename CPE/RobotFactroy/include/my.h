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
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdbool.h>

typedef struct {
    int nb_mots;
    char **mots;
    int index_mot;
    int len;
    int dans_mot;
    int in_quotes;
} words_t;

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
int my_strtol_sub(const char *str, char **endptr);
char *my_strncpy(char *dest, const char *src, unsigned long n);
int extract_numbers(const char *str, int *numbers, int max_numbers);
void its(int number, char *result);
char **my_str_to_word_array(const char *chaine, const char *separateurs);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int my_putstr(char const *str);
char **my_argv_to_array(int argc, char **argv);
void free_argv_array(char **array, int argc);
char *my_itoa(int value);
int my_strncmp(const char *str1, const char *str2, size_t n);
size_t my_strcspn(const char *str, const char *reject);
char *my_strrchr(const char *str, int ch);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);
int my_get_nbr(const char *str);
int my_isdigit(char character);
int my_isalpha(char character);
char my_toupper(char character);
bool my_isxdigit(char c);

#endif /* MY_H */
