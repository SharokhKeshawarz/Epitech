/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** delimite commands
*/

#include "../include/pmy.h"
#include "../include/my.h"

static int check_good_ending(char **av)
{
    int temp = 0;
    int count = 0;

    for (int tmp = 0; av[tmp] != NULL; tmp++) {
        if (my_strchr(av[tmp][0], ")") == 2)
            temp++;
        if (my_strchr(av[tmp][0], "(") == 2)
            count++;
    }
    if (temp > count)
        return my_perror("Too many )'s.\n", NULL, NULL, NULL);
    else if (temp < count)
        return my_perror("Too many ('s.\n", NULL, NULL, NULL);
    return 0;
}

static int check_par_next(char **av, int a)
{
    if (my_strchr(av[a][0], "()") == 0)
        return 0;
    if (my_strchr(av[a][0], "(") == 2) {
        if (a == 0)
            return 0;
        if (a > 0 && ((av[a - 1][1] && av[a - 1][0] == 1 &&
        strchr(";&|", av[a - 1][1])) || (my_strchr(av[a - 1][0], "(") == 2))) {
            return 0;
        } else
            return my_perror("Badly placed ()'s.\n", NULL, NULL, NULL);
    }
    if (a == 0 || my_strchr(av[a - 1][0], "(") == 2)
        return my_perror("Invalid null command.\n", NULL, NULL, NULL);
    return 0;
}

static char **check_par(char **argv)
{
    int test = 0;

    if (check_good_ending(argv) != 0)
        return mygetfree(argv);
    for (int a = 0; argv && argv[a]; a++) {
        if (check_par_next(argv, a) == 1)
            return mygetfree(argv);
    }
    return argv;
}
