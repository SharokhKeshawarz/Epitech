/*
** EPITECH PROJECT, 2023
** my_rev_list()
** File description:
** Reverse an array of linked list
*/

#include "include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *prev = 0;
    linked_list_t *current = *begin;
    linked_list_t *next = 0;

    while (current != 0) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}
