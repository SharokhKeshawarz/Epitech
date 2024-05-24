/*
** EPITECH PROJECT, 2023
** sort.c
** File description:
** sort
*/

#include "include/main.h"

void swap(list_t *a, list_t *b)
{
    void *temp_data = a->data;
    size_t temp_id = a->id;

    a->data = b->data;
    a->id = b->id;
    b->data = temp_data;
    b->id = temp_id;
}

void check_swap_condition(list_t *ptr1, list_t *lptr, int *swapped)
{
    if (ptr1->id < ptr1->next->id) {
        swap(ptr1, ptr1->next);
        *swapped = 1;
    }
}

void sort_reverse(list_t *head)
{
    int swapped;
    list_t *ptr1;
    list_t *lptr = NULL;

    if (head == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            check_swap_condition(ptr1, lptr, &swapped);
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int sort(void *data, char **argv)
{
    list_t *head = *(list_t **)data;

    if (argv[0] == NULL || head == NULL)
        return 84;
    if (my_strcmp(argv[0], "ID") == 0)
        sort_reverse(head);
    return 0;
}
