/*
** EPITECH PROJECT, 2023
** my_delete_nodes()
** File description:
** Deletes Nodes
*/

#include "include/mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *prev = 0;
    linked_list_t *current = *begin;

    for (int i = 0; current != 0; i++) {
        if (cmp(current->data, data_ref)) {
            prev->next = current->next;
            free(current->data);
            free(current);
            return 1;
        }
        prev = current;
        current = prev;
    }
    return 0;
}
