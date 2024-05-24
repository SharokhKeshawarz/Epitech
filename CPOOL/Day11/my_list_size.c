/*
** EPITECH PROJECT, 2023
** my_list_size()
** File description:
** Returns the size of the list
*/

#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *tmp = begin;
    int length = 0;

    while (tmp != 0) {
        tmp = tmp->next;
        length++;
    }
    return length;
}
