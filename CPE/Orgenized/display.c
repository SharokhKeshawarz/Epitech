/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display
*/

#include "include/main.h"

int disp(void *data, char **argv)
{
    list_t *head = *(list_t **)data;

    if (head != NULL)
        print_list(head);
    else
        my_printf("Linked list is empty\n");
    return 0;
}
