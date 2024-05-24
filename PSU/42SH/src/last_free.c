/*
** EPITECH PROJECT, 2024
** last free
** File description:
** Make sure to not leave any trace behind...
*/

#include "../include/pmy.h"
#include "../include/my.h"

void last_free(char ***enve, char *testline, general_t *general)
{
    free(enve);
    free(testline);
    if (general->clipboard != NULL)
        free(general->clipboard);
    free(general);
}
