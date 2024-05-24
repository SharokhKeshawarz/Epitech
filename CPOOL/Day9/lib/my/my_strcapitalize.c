/*
** EPITECH PROJECT, 2023
** my_strcapitalize()
** File description:
** Capitelize a string
*/

int is_seperator(char c)
{
    return c == '\t' || c == ' ' || c == '\n' || c == '+' || c == '-';
}

int check_alpha(char *str, int i)
{
    if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
        return 1;
    else
        return 0;
}

void check_upper(char *str, int i, int *word)
{
    if (*word == 1) {
        str[i] = str[i] - 32;
        *word = 0;
    } else {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int word = 1;

    if (str[0] >= 65 && str[0] <= 90) {
        i = 1;
        word = 0;
    }
    while (str[i]) {
        if (check_alpha(str, i) == 1) {
            check_upper(str, i, &word);
        } else
            word = is_seperator(str[i]);
        i++;
    }
    return str;
}
