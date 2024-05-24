/*
** EPITECH PROJECT, 2023
** my_print_params()
** File description:
** Prints all the parameters
*/

void my_putstr_print(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void my_print_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr_print(argv[i]);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    my_print_params(argc, argv);
    return 0;
}
