/*
** EPITECH PROJECT, 2023
** mylist.h
** File description:
** Struct of a linked list
*/

#ifndef MYLIST_H
    #define MYLIST_H

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
#endif
