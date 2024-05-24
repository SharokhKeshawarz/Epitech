/*
** EPITECH PROJECT, 2023
** create_delete.c
** File description:
** create_delete
*/

#include "include/hashtable.h"


int nbr_positif(int x)
{
    return (x < 0) ? -x : x;
}

int hash(char *key, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += key[i];
        sum = sum * key[0] * key[i - 1];
    }
    sum = (sum << 5) ^ (sum >> 3);
    return nbr_positif(sum);
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *table = malloc(sizeof(hashtable_t));

    if (table == NULL || len <= 0)
        return NULL;
    table->size = len;
    table->hash = hash;
    table->array = malloc(len * sizeof(list_t *));
    if (table->array == NULL || hash == NULL) {
        free(table);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        table->array[i] = NULL;
    return table;
}

int delete_hashtable(hashtable_t *ht)
{
    list_t *current;
    list_t *next;

    if (ht == NULL || ht->array == NULL)
        return 84;
    for (int i = 0; i < ht->size; ++i) {
        current = ht->array[i];
        while (current != NULL) {
            next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }
    }
    free(ht->array);
    free(ht);
}
