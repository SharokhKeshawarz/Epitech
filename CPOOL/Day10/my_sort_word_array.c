/*
** EPITECH PROJECT, 2023
** my_sort_word_array()
** File description:
** Sorts an array of word
*/

int my_sort_word_array(char **tab)
{
    int length;
    int i = 0;
    char *temp;

    for (length = 0; tab[i] != 0; length++);
    while (i < length) {
        if (i == 0)
            continue;
        if (my_strcmp(tab[i], tab[i - 1]) < 0) {
            temp = tab[i - 1];
            tab[i - 1] = tab[i];
            tab[i] = temp;
            my_sort_word_array(temp);
            break;
        }
        i++;
    }
    return 0;
}
