/*
** EPITECH PROJECT, 2023
** my_apply_on_nodes()
** File description:
** Applays a function to a node data
*/

#include "include/mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *temp = begin;

    for (int i = 0; temp != 0; i++) {
        temp->data = (f)(temp->data);
        temp = temp->next;
    }
    return 0;
}
