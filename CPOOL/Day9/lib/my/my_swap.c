/*
** EPITECH PROJECT, 2023
** my_swap()
** File description:
** Swaps all variables
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
