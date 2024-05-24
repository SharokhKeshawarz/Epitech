/*
** EPITECH PROJECT, 2023
** my_print_revalpha()
** File description:
** Printing alphabet in reverse order
*/

int my_print_revalpha(void)
{
    for (int i = 122; i >= 97; i--) {
        my_putchar(i);
    }
    return 0;
}
