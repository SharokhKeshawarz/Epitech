/*
** EPITECH PROJECT, 2023
** concate_params()
** File description:
** Concatinates parameters
*/

char *concat_params(int argc, char **argv)
{
    int total_length = 0;
    char *result;

    if (argc == 0)
        return;
    for (int i = 0; i < argc; i++)
        total_length += my_strlen(argv[i]) + 1;
    result = (char *)malloc(total_length);
    for (int j = 0; j < argc; j++) {
        my_strcat(result, argv[j]);
        if (j < argc - 1)
            my_strcat(result, "\n");
    }
    result[total_length] = '\0';
    return result;
}
