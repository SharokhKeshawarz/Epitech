/*
** EPITECH PROJECT, 2023
** my_sort_params.c
** File description:
** It sorts parameters in ascii order
*/

static void my_putstr_sort(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

static char *my_strcpy_sort(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

static int my_strlen_sort(char const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return length;
}

static void swap_str(char *str1, char *str2)
{
    char temp[my_strlen_sort(str1)];

    my_strcpy_sort(temp, str1);
    my_strcpy_sort(str1, str2);
    my_strcpy_sort(str2, temp);
}

int my_strcmp_str(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void check_swaping(char **argv, int j)
{
    if (my_strcmp_str(argv[j], argv[j + 1]) > 0)
        swap_str(&argv[j], &argv[j + 1]);
}

void sort_array(int argc, char **argv)
{
    int i;
    int j;

    for (i = 0; i < argc - 1; i++) {
        for (j = 0; j < argc - i - 1; j++) {
            check_swaping(argv, j);
        }
    }
}

void my_sort_params(char argc, char **argv)
{
    sort_array(argc, argv);
    for (int i = 0; i < argc; i++) {
        my_putstr_sort(argv[i]);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    my_sort_params(argc, argv);
    return 0;
}
