/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** All prototypes of the functions in libmy.a
*/

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
void my_show_word_array(char *const *tab);
int check_prime(int n);
void check_letters(char const *str, int *index, int *negative);
int int_size(long number, int number_length);
static void check_conditions(int nb);
int base_length(char const *str);
void reverse_characters(char *str, int length);
static void check_value(int *array, int j);
static int is_alphanum(char c);
struct WordInfo;
int index_word_2(char *str, int i, struct WordInfo *wordInfo, int word);
static int index_word(char *str, int word);
static void count_words_2(int *is_word, int *counter);
int count_words(char *str);
void count_word_letter_2(int *is_word, int *counter, int *letter, int word);
int count_word_letter(char *str, int word);
int is_seperator(char c);
int check_alpha(char *str, int i);
void check_upper(char *str, int i, int *word);
int strlen_cat(char *const str);
int strlen_catn(char const *str);
int len_strcmp(char const *str);
void my_putnbr_base(int nbr, char const *base);
#endif
