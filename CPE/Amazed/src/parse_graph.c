/*
** EPITECH PROJECT, 2024
** parse_graph.c
** File description:
** parse_graph
*/

#include "../include/main.h"

static void fill_graph_array(file_t *file, size_t i, size_t *k)
{
    char temp1;
    char temp2;
    char temp3;

    for (size_t j = 0; file->array[i][j] != '\0'; j++) {
        temp1 = file->array[i][j];
        temp2 = file->array[i][j + 1];
        temp3 = file->array[i][j + 2];
        if (temp1 == '\0' || temp2 == '\0' || temp3 == '\0')
            continue;
        if (my_isdigit(temp1) && temp2 == '-' && my_isdigit(temp3)) {
            file->graph[*k] = my_strdup(file->array[i]);
            (*k)++;
        }
    }
}

static void parse_graph_2(file_t *file, graph_t *graph, size_t i, size_t *k)
{
    char temp1;
    char temp2;
    char temp3;

    for (size_t j = 0; file->array[i][j] != '\0'; j++) {
        temp1 = file->array[i][j];
        temp2 = file->array[i][j + 1];
        temp3 = file->array[i][j + 2];
        if (temp1 == '\0' || temp2 == '\0' || temp3 == '\0')
            continue;
        if (my_isdigit(temp1) && temp2 == '-' && my_isdigit(temp3)) {
            add_edge(graph, temp1 - 48, temp3 - 48);
            (*k)++;
        }
    }
}

graph_t *parse_graph(file_t *file)
{
    graph_t *graph = create_graph(file->number_robots);
    size_t k = 0;
    size_t l = 0;

    for (size_t i = 0; file->array[i] != NULL; i++)
        parse_graph_2(file, graph, i, &k);
    file->graph = malloc(sizeof(char *) * ((k) + 1));
    file->graph[k] = NULL;
    k = 0;
    for (size_t i = 0; file->array[i] != NULL; i++)
        fill_graph_array(file, i, &k);
    return graph;
}
