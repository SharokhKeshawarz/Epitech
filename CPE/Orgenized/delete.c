/*
** EPITECH PROJECT, 2023
** delete.c
** File description:
** delete
*/

#include "include/main.h"

static list_t *get_node_by_id(list_t *head, size_t id)
{
    list_t *current = head;

    while (current != NULL) {
        if (current->id == id)
            return current;
        current = current->next;
    }
    return NULL;
}

static void print_list_deleting(list_t *deleted_element)
{
    char *data;
    char *type;
    char *material;

    if (deleted_element != NULL) {
        data = my_strdup((char *)(deleted_element->data));
        type = my_strtok(data, " ");
        material = my_strtok(NULL, "");
        my_printf(
            "%s n°%d - \"%s\" deleted.\n",
            type, (int)(deleted_element->id), material
        );
        free(data);
    }
}

static void process_token(list_t ***head, const char *token)
{
    size_t id_to_delete = my_atoi(token);
    list_t *deleted_node = get_node_by_id(**head, id_to_delete);

    if (deleted_node != NULL) {
        print_list_deleting(deleted_node);
        delete_node_by_id(*head, id_to_delete);
    } else
        my_printf("ID %d not found in the linked list.\n", id_to_delete);
}

static void delete_node_if_exists(list_t ***head, const char *input)
{
    char *token = my_strtok(input, ",");

    while (token != NULL) {
        process_token(head, token);
        token = my_strtok(NULL, ",");
    }
}

int del(void *data, char **argv)
{
    list_t **head = (list_t **)data;
    int i = 0;

    if (*head != NULL && argv[0] != NULL) {
        while (argv[i] != NULL) {
            delete_node_if_exists(&head, argv[i]);
            i++;
        }
    } else {
        my_printf("Cannot delete from an empty list or invalid ID.\n");
    }
    return 0;
}
