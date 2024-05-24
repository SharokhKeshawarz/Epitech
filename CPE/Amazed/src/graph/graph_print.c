/*
** EPITECH PROJECT, 2024
** graph_print.c
** File description:
** graph_print
*/

#include "../../include/main.h"

static void print_graph_2(graph_t *graph, size_t i, size_t j)
{
    if (graph->edges[i][j])
        my_printf("%d-%d\n", i, j);
}

void print_graph(graph_t *graph)
{
    my_printf("digraph {\n");
    for (size_t i = 0; i < graph->n_nodes; i++) {
        for (size_t j = 0; j < graph->n_nodes; j++)
            print_graph_2(graph, i, j);
    }
    my_printf("}\n");
}

static void print_graph_matrix_2(graph_t *graph, int i, int j)
{
    if (graph->edges[i][j] == true)
        my_printf("\033[32m%d\033[0m", graph->edges[i][j]);
    else
        my_printf("%d", graph->edges[i][j]);
    if (j != graph->n_nodes - 1)
        my_printf(" ");
}

void print_graph_matrix(graph_t *graph)
{
    my_printf("  ");
    for (int i = 0; i < graph->n_nodes; i++) {
        my_printf("\033[31m%d\033[0m", i);
        if (i != graph->n_nodes - 1)
            my_printf(" ");
    }
    my_printf("\n");
    for (int i = 0; i < graph->n_nodes; i++) {
        my_printf("\033[31m%d\033[0m ", i);
        for (int j = 0; j < graph->n_nodes; j++)
            print_graph_matrix_2(graph, i, j);
        my_printf("\n");
    }
    my_printf("\n");
}
