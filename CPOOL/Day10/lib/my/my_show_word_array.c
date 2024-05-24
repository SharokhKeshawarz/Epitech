/*
** EPITECH PROJECT, 2023
** my_show_word_array()
** File description:
** Shows there content of an string array
*/

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
