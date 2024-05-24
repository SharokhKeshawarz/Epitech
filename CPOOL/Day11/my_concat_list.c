/*
** EPITECH PROJECT, 2023
** my_concat_list()
** File description:
** Concates two lists
*/

#include "include/mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *current = *begin1;

    while (current->next != 0)
        current = current->next;
    current->next = begin2;
}
