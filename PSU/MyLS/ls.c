/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

static void check_space_ls(char **array, int i, int size)
{
    my_printf("%s", array[i]);
    if (i != size)
        my_printf("  ");
    free(array[i]);
}

int my_ls(int argc, char **argv, char const *path, flags *present_flags)
{
    char **array = create_array(path, *present_flags);
    int size = count_elements(path, *present_flags);

    if (array == NULL || size == 84)
        return 84;
    if (present_flags->r == false) {
        for (int i = 0; i < size; i++)
            check_space_ls(array, i, size - 1);
    } else {
        for (int i = size - 1; i >= 0; i--)
            check_space_ls(array, i, 0);
    }
    my_printf("\n");
    free(array);
}
