/*
** EPITECH PROJECT, 2018
** MY.H
** File description:
** my.h
*/

#ifndef MY
    #define MY
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>

void my_putchar(char);
void my_putchart(char *);
void my_put_nbr(int);
void my_putstr(char const *);
int my_strlen(char const *);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
char *my_strncat(char *, char const *, int);
int my_str_isupper(char const *);
int my_str_isalpha(char const *);
int my_str_isprintable(char const *);
char *my_strlowcase(char *);
int my_str_isnum(char const *);
int my_strcmp(char const *, char const *);
int my_str_islower(char const *);
int my_is_prime(int);
int my_compute_square_root(int);
int my_getnbr(char const *);
int my_find_prime_sup(int);
int my_compute_power_rec(int, int);
int my_printf(const char *format, ...);
char *my_strdup(char *);
int my_strnxcmp(const char *s1, const char *s2, size_t n);
char *my_setstringbegin(char *s1, char *s2);
char *my_setstringend(char *s1, char *s2);
char **my_str_to_word_array(const char *chaine, const char *separateurs);
char *my_strdupcaraccp(char carac, int len);

#endif
