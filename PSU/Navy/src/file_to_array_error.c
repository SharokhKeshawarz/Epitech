/*
** EPITECH PROJECT, 2024
** error handling files
** File description:
** error handling files
*/

#include "../include/proto.h"

int column_checker(file_t *file)
{
    int len = 0;

    for (int i = 0; file->array[i] != NULL; i++)
        if (my_strlen(file->array[i]) != 7)
            return 84;
    return 0;
}

static int checking_str(char *str)
{
    char *tmp = malloc(sizeof(char) * 2);
    int result = 0;

    tmp[0] = str[0];
    tmp[1] = '\0';
    result = (str[6] + str[5]) - (str[3] + str[2]);
    result = result - my_getnbr(tmp);
    free(tmp);
    return result;
}

int error_handling_files(file_t *file)
{
    int result = 0;

    for (int i = 0; file->array[i] != NULL; i++) {
        result = checking_str(file->array[i]);
        if (result != -1)
            return 84;
    }
    return 0;
}
