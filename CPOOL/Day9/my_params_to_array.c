/*
** EPITECH PROJECT, 2023
** my_params_to_array()
** File description:
** Turns the argv to an array of struct
*/

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *info_array;
    int len = 0;

    info_array = (struct info_param *)malloc(ac * sizeof(struct info_param));
    for (int i = 0; i < ac; i++) {
        info_array[i].length = my_strlen(av[i]);
        info_array[i].str = av[i];
        len = my_strlen(av[i]) + 1;
        info_array[i].copy = (char *)malloc(len * sizeof(char));
        my_strcpy(info_array[i].copy, av[i]);
        info_array[i].word_array = my_str_to_word_array(av[i]);
    }
    return info_array;
}
