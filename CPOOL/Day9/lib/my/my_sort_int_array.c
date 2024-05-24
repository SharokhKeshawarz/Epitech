/*
** EPITECH PROJECT, 2023
** my_sort_int_array()
** File description:
** Sorts an array in asending order
*/

static void check_value(int *array, int j)
{
    int temp = 0;

    if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
}

int my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            check_value(array, j);
        }
    }
    return 0;
}
