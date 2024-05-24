/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

static void check_and_swap(char **array, int i, int *swapped)
{
    char *temp;

    if (my_strcasecmp(array[i], array[i + 1]) > 0) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        *swapped = 1;
    }
}

void custom_sort(char **array, int size)
{
    int swapped;

    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++)
            check_and_swap(array, i, &swapped);
    } while (swapped);
}

static void swap_entries_t(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}

static int should_swap_entries_ls_t(char *pathA, char *pathB)
{
    struct stat statA;
    struct stat statB;

    lstat(pathA, &statA);
    lstat(pathB, &statB);
    return (statB.st_mtime > statA.st_mtime);
}

static void swap_if_necessary_ls_t(char **entries, int indexA, int indexB)
{
    char *pathA = (char *)malloc(1024);
    char *pathB = (char *)malloc(1024);

    my_strcpy(pathA, entries[indexA]);
    my_strcpy(pathB, entries[indexB]);
    if (should_swap_entries_ls_t(pathA, pathB))
        swap_entries_t(&entries[indexA], &entries[indexB]);
    free(pathA);
    free(pathB);
}

void sort_entries_ls_t(char **entries, int num_entries)
{
    for (int i = 0; i < num_entries - 1; i++)
        for (int j = 0; j < num_entries - i - 1; j++)
            swap_if_necessary_ls_t(entries, j, j + 1);
}
