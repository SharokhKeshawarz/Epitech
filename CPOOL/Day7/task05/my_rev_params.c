/*
** EPITECH PROJECT, 2023
** my_rev_params()
** File description:
** Prints the parameters in reverse
*/

void my_putstr_rev(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void my_rev_params(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr_rev(argv[i]);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    my_rev_params(argc, argv);
    return 0;
}
