/*
** EPITECH PROJECT, 2023
** my_params_to_list()
** File description:
** Converts params to a linked list
*/

#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *current = 0;
    linked_list_t *new_node;

    for (int i = 0; i < ac; i++) {
        new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
        new_node->data = av[i];
        new_node->next = current;
        current = new_node;
    }
    return new_node;
}
