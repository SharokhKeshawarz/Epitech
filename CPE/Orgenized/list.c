/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** list
*/

#include "include/main.h"

void print_list(list_t *head)
{
    char *data;
    char *type;
    char *material;

    if (head == NULL)
        return;
    print_list(head->next);
    data = my_strdup((char *)(head->data));
    type = my_strtok(data, " ");
    material = my_strtok(NULL, "");
    my_printf("%s n°%d - \"%s\"\n", type, (int *)(head->id), material);
    free(data);
}

void insert_at_beginning(list_t **head, void *new_data)
{
    list_t *new_node = (list_t *)malloc(sizeof(list_t));

    new_node->data = my_strdup(new_data);
    new_node->next = *head;
    new_node->id = (*head == NULL) ? 0 : (*head)->id + 1;
    *head = new_node;
}

void insert_at_end(list_t **head, void *new_data)
{
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    list_t *last = *head;

    new_node->data = my_strdup(new_data);
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->id = 0;
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    new_node->id = last->id + 1;
    last->next = new_node;
}

int compare_string(const void *str1, const void *str2)
{
    return my_strcmp((char *)str1, (char *)str2);
}

void delete_node_by_id(list_t **head, size_t id)
{
    list_t *temp = *head;
    list_t *prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp->data);
        free(temp);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp->data);
    free(temp);
}
