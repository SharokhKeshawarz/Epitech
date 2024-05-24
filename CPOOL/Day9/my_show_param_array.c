/*
** EPITECH PROJECT, 2023
** my_show_param_array()
** File description:
** Shows the parameters of argc and argv
*/

int my_show_param_array(struct info_params const *par)
{
    for (int i = 0; i < par[i].str != 0; i++) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_putstr(par[i].copy);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        my_putchar('\n');
    }
    return 0;
}
