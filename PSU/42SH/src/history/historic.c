/*
** EPITECH PROJECT, 2024
** miniShell
** File description:
** main.c
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

void historic_time(history_t *new, time_t current_time)
{
    char time_str[6];
    struct tm *timeinfo = localtime(&current_time);

    if (timeinfo == NULL) {
        fprintf(stderr, "Error converting time\n");
        new->clock = NULL;
    } else {
        strftime(time_str, sizeof(time_str), "%H:%M", timeinfo);
        new->clock = strdup(time_str);
        if (new->clock == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(new->line_com);
            free(new);
            return;
        }
    }
}

void add_historic(history_t **historic, char *str)
{
    int compteur = (*historic)->nb;
    history_t *new = malloc(sizeof(history_t));
    time_t current_time = time(NULL);

    if (new == NULL)
        return;
    new->line_com = strdup(str);
    if (new->line_com == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(new);
        return;
    }
    new->nb = 0;
    new->nb = compteur + 1;
    if (current_time == -1)
        new->clock = NULL;
    else
        historic_time(new, current_time);
    new->next = *historic;
    *historic = new;
}

void loop_history(history_t *historic, int nbr)
{
    if (historic && nbr > 0) {
        loop_history(historic->next, nbr - 1);
        if (historic->clock && historic->line_com) {
            my_printf("    %d %s %s\n", historic->nb,
            historic->clock, historic->line_com);
        }
    }
}

void view_history(history_t **historic, char *argum)
{
    int nbr = 1000;

    if (argum)
        nbr = my_getnbr(argum);
    if (nbr < 1)
        nbr = 1;
    loop_history(*historic, nbr);
}

void free_historic(history_t **historic)
{
    history_t *temp;

    for (history_t *head = *historic; head; head = temp) {
        temp = head->next;
        free(head->line_com);
        free(head);
    }
    free(historic);
}
