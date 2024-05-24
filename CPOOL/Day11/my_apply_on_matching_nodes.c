/*
** EPITECH PROJECT, 2023
** my_apply_on_matching_nodes()
** File description:
** Applays a function to a node data matching
*/

#include "include/mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin,
    int (*f)(),
    void const *data_ref,
    int (*cmp)())
{
    linked_list_t *temp = begin;

    for (int i = 0; temp != 0; i++) {
        if (cmp(temp->data, data_ref))
            temp->data = (f)(temp->data);
        temp = temp->next;
    }
    return 0;
}
