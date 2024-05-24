/*
** EPITECH PROJECT, 2023
** main.h
** File description:
** main
*/

#ifndef MAIN_H
    #define MAIN_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include "my.h"
    #include "../shell/shell.h"

typedef struct list_t {
    void *data;
    size_t id;
    struct list_t *next;
} list_t;

void print_list(list_t *head);
void insert_at_beginning(list_t **head, void *new_data);
void insert_at_end(list_t **head, void *new_data);
int compare_string(const void *str1, const void *str2);
void delete_node_by_id(list_t **head, size_t id);

static list_t *get_last_node(list_t *head);
static void print_list_adding(list_t *new_element);

static list_t *get_node_by_id(list_t *head, size_t id);
static void print_list_deleting(list_t *deleted_element);



#endif
