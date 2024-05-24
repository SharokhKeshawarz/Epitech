/*
** EPITECH PROJECT, 2023
** my_find_node()
** File description:
** Returns the first node of a matching data
*/

#include "include/mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data_ref,
    int (*cmp)())
{
    linked_list_t *temp = begin;

    for (int i = 0; temp != 0; i++) {
        if (cmp(temp->data, data_ref))
            return temp;
        temp = temp->next;
    }
    return 0;
}
