/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

static void check_and_swap_entries(struct dirent **entriy, int n, int *swapped)
{
    struct dirent *temp;

    for (int i = 0; i < n - 1; i++) {
        if (my_strcasecmp(entriy[i]->d_name, entriy[i + 1]->d_name) > 0) {
            temp = entriy[i];
            entriy[i] = entriy[i + 1];
            entriy[i + 1] = temp;
            *swapped = 1;
        }
    }
}

void sort_entries(struct dirent **entries, int num_entries)
{
    int swapped;

    do {
        swapped = 0;
        check_and_swap_entries(entries, num_entries, &swapped);
    } while (swapped);
}

static void swap_entries_ls_l_t(struct dirent **a, struct dirent **b)
{
    struct dirent *temp = *a;

    *a = *b;
    *b = temp;
}

static int should_swap_entries_ls_l_t(struct dirent *A, struct dirent *B)
{
    char pathA[1024];
    char pathB[1024];
    struct stat statA;
    struct stat statB;

    my_strcpy(pathA, A->d_name);
    my_strcpy(pathB, B->d_name);
    lstat(pathA, &statA);
    lstat(pathB, &statB);
    return (statB.st_mtime > statA.st_mtime);
}

static void swap_if_necessary_ls_l_t(struct dirent **entries, int A, int B)
{
    if (should_swap_entries_ls_l_t(entries[A], entries[B]))
        swap_entries_ls_l_t(&entries[A], &entries[B]);
}

void sort_entries_ls_l_t(struct dirent **entries, int num_entries)
{
    for (int i = 0; i < num_entries - 1; i++)
        for (int j = 0; j < num_entries - i - 1; j++)
            swap_if_necessary_ls_l_t(entries, j, j + 1);
}
