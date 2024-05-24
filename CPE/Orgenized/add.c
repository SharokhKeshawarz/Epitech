/*
** EPITECH PROJECT, 2023
** add.c
** File description:
** add
*/

#include "include/main.h"

static list_t *get_last_node(list_t *head)
{
    list_t *current;

    if (head == NULL)
        return NULL;
    current = head;
    while (current->next != NULL)
        current = current->next;
    return current;
}

static void print_list_adding(list_t *new_element)
{
    char *data;
    char *type;
    char *material;

    if (new_element != NULL) {
        data = my_strdup((char *)(new_element->data));
        type = my_strtok(data, " ");
        material = my_strtok(NULL, "");
        my_printf(
            "%s n°%d - \"%s\" added.\n", type, (int)(new_element->id), material
        );
        free(data);
    }
}

int add(void *data, char **argv)
{
    int i = 0;
    char *buffer;
    int length;
    list_t *last_added = NULL;

    while (argv[i] != NULL && argv[i + 1] != NULL) {
        length = my_strlen(argv[i]) + my_strlen(argv[i + 1]) + 2;
        buffer = (char *)malloc(length);
        my_strcpy(buffer, argv[i]);
        my_strcat(buffer, " ");
        my_strcat(buffer, argv[i + 1]);
        insert_at_end((list_t **)data, buffer);
        last_added = get_last_node(*(list_t **)data);
        print_list_adding(last_added);
        i += 2;
    }
    return 0;
}
