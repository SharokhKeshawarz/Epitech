/*
** EPITECH PROJECT, 2023
** crud.c
** File description:
** crud
*/

#include "include/hashtable.h"
#include <stdio.h>

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;
    list_t *current;

    if (ht == NULL || key == NULL || my_strlen(key) <= 0)
        return NULL;
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->array[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}

int ht_dump(hashtable_t *ht)
{
    list_t *current;

    if (ht == NULL)
        return 84;
    for (int i = 0; i < ht->size; i++) {
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:\n");
        current = ht->array[i];
        while (current != NULL) {
            my_putstr("> ");
            my_put_nbr(
                ht->hash(current->key, my_strlen(current->key)) % ht->size);
            my_putstr(" - ");
            my_putstr(current->value);
            my_putchar('\n');
            current = current->next;
        }
    }
    return 0;
}

static list_t *new_key_value_pair(char *key, char *value)
{
    list_t *new_pair = malloc(sizeof(list_t));

    if (my_strlen(key) <= 0 || my_strlen(value) <= 0)
        return NULL;
    if (new_pair == NULL || key == NULL || value == NULL)
        return NULL;
    new_pair->key = my_strdup(key);
    new_pair->value = my_strdup(value);
    new_pair->next = NULL;
    return new_pair;
}

static ht_insert_s1(hashtable_t *ht, char *key, char *value)
{
    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    return 0;
}

static int ht_insert_s2(char *key, char *value)
{
    if (my_strlen(key) <= 0 || my_strlen(value) <= 0)
        return 84;
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = 0;
    list_t *current;
    list_t *new_pair;

    if (ht_insert_s1(ht, key, value) == 84 || ht_insert_s2(key, value) == 84)
        return 84;
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->array[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            free(current->value);
            current->value = my_strdup(value);
            return 1;
        }
        current = current->next;
    }
    new_pair = new_key_value_pair(key, value);
    new_pair->next = ht->array[index];
    ht->array[index] = new_pair;
    return 1;
}

static void ht_delete_2(hashtable_t *ht, list_t *curr, list_t *prev, int index)
{
    if (prev == NULL)
        ht->array[index] = curr->next;
    else
        prev->next = curr->next;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = 0;
    list_t *current;
    list_t *prev = NULL;

    if (ht == NULL || key == NULL || my_strlen(key) <= 0)
        return 84;
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->array[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            ht_delete_2(ht, current, prev, index);
            free(current->key);
            free(current->value);
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 84;
}
