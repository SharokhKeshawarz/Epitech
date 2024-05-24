/*
** EPITECH PROJECT, 2024
** graph.c
** File description:
** graph
*/

#include "../../include/main.h"

graph_t *create_graph(size_t n_nodes)
{
    graph_t *graph = malloc(sizeof(graph_t));

    if (graph == NULL)
        return NULL;
    graph->n_nodes = n_nodes;
    graph->edges = malloc(sizeof(bool *) * n_nodes);
    if (graph->edges == NULL) {
        free(graph);
        return NULL;
    }
    for (size_t i = 0; i < n_nodes; i++) {
        graph->edges[i] = malloc(sizeof(bool) * n_nodes);
        if (graph->edges[i] == NULL)
            return NULL;
        for (int j = 0; j < n_nodes; j++)
            graph->edges[i][j] = false;
    }
    return graph;
}

void destroy_graph(graph_t *graph)
{
    if (graph->edges == NULL)
        return;
    for (int i = 0; i < graph->n_nodes; i++) {
        if (graph->edges[i] != NULL)
            free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}

bool add_edge(graph_t *graph, size_t from, size_t to)
{
    if (has_edge(graph, from, to))
        return false;
    graph->edges[from][to] = true;
    return true;
}

bool has_edge(graph_t *graph, size_t from, size_t to)
{
    return graph->edges[from][to];
}
