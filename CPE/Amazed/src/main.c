/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../include/main.h"

static void print_them(file_t *file)
{
    my_printf("#number_of_robots\n");
    my_printf("%d\n", file->number_robots - 1);
    my_printf("#rooms\n");
    my_printf("##start\n");
    my_printf("%s\n", file->start);
    my_printf("##end\n");
    my_printf("%s\n", file->end);
    my_printf("#tunnels\n");
    for (int i = 0; file->graph[i] != NULL; i++)
        my_printf("%s\n", file->graph[i]);
    my_printf("#moves\n");
}

int main(int argc, char const *argv[])
{
    file_t *file = malloc(sizeof(file_t));
    graph_t *graph;

    file->array = create_array();
    if (parse_nb_robots(file) == 84)
        return 84;
    parse_start_end(file);
    graph = parse_graph(file);
    print_them(file);
    return 0;
}
