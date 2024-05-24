/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <unistd.h>
    #include <stdlib.h>

typedef struct list_t {
    char *key;
    char *value;
    struct list_t *next;
} list_t;

typedef struct hashtable_s {
    int size;
    int (*hash)(char *, int);
    struct list_t **array;
} hashtable_t;

// Lib
int my_put_nbr(int nb);
int my_strcmp(const char *str1, const char *str2);
char *my_strdup(const char *str);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);

// Hash function
int nbr_positif(int x);
int hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
int delete_hashtable(hashtable_t *ht);

// Handle table functions
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
int ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
