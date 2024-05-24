/*
** EPITECH PROJECT, 2024
** main.h
** File description:
** main
*/

#ifndef MAIN_H
    #define MAIN_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include "my.h"
    #include "my_printf.h"

typedef struct file_s {
    char **array;
    char **graph;
    size_t number_robots;
    size_t lap;
    char *start;
    char **after_start;
    char *end;
    char **after_end;
    char **rooms;
} file_t;

typedef struct graph_s {
    int n_nodes;
    bool **edges;
} graph_t;

graph_t *create_graph(size_t n_nodes);
char **create_array(void);
void destroy_graph(graph_t *graph);
void print_graph(graph_t *graph);
void print_graph_matrix(graph_t *graph);
bool add_edge(graph_t *graph, size_t from_node, size_t to_node);
bool has_edge(graph_t *graph, size_t from_node, size_t to_node);
int parse_nb_robots(file_t *file);
void parse_start_end(file_t *file);
graph_t *parse_graph(file_t *file);

#endif
