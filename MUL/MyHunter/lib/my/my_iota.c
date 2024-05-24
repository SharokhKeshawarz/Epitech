/*
** EPITECH PROJECT, 2023
** put_str()
** File description:
** put_str
*/

int my_itoa_2(int value, int *i, char result[12])
{
    if (value == 0) {
        result[*i] = '0';
        (*i)++;
        return 0;
    } else if (value < 0) {
        result[*i] = '-';
        (*i)++;
        value = -value;
    }
    return -1;
}

char *my_itoa(int value)
{
    char *result = (char *)malloc(12 * sizeof(char));
    int i = 0;
    char temp;

    if (my_itoa_2(value, &i, result) == 0)
        return result;
    else {
        while (value != 0) {
            result[i] = '0' + value % 10;
            value /= 10;
            i++;
        }
        for (int j = 0; j < i / 2; ++j) {
            temp = result[j];
            result[j] = result[i - j - 1];
            result[i - j - 1] = temp;
        }
    }
    result[i] = '\0';
    return result;
}
