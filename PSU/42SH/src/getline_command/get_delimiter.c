/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** delimite commands
*/

#include "../include/pmy.h"
#include "../include/my.h"

char *add_in_argv(char carac, int *fir_ct, int nbr)
{
    char *new = my_strdupcaraccp(carac, nbr);

    fir_ct[1]++;
    return new;
}

int my_strchr(char carac, char *orig)
{
    char *separators = malloc(sizeof(char) * (my_strlen(orig) + 1));
    int i = 0;

    for (; orig[i]; i++) {
        separators[i] = orig[i] + 95;
    }
    separators[i] = '\0';
    i = 0;
    if (carac == '\0')
        return i;
    if (strchr(separators, carac))
        i = 2;
    free(separators);
    return i;
}

int have_a_delimiter(int *fir_ct, int b, char *ar, char **new)
{
    if (my_strchr(ar[b], ";") == 2) {
        for (; my_strchr(ar[b + fir_ct[2]], ";") == 2; fir_ct[2]++);
    } else if (ar[b + 2] && ar[b] == ar[b + 1] && ar[b] == ar[b + 2])
        return -1;
    if (b != 0) {
        new[fir_ct[1]] = my_strduplen(&ar[fir_ct[0]], b - fir_ct[0]);
        fir_ct[1]++;
    }
    if (ar[b + 1] && ar[b] == ar[b + 1] && my_strchr(ar[b], ";") == 0) {
        new[fir_ct[1]] = add_in_argv(ar[b], fir_ct, 2);
        fir_ct[0] = b + 1;
        fir_ct[2] += 2;
    }
    if (ar[b + 1] && ar[b] != ar[b + 1] || !ar[b + 1] ||
    my_strchr(ar[b], ";") == 2){
        new[fir_ct[1]] = add_in_argv(ar[b], fir_ct, 1);
        fir_ct[0] = b + 1;
    }
    return 0;
}

char **more_argv(char **argv, char **new)
{
    int count = 0;
    int max = 0;

    for (int a = 0; argv[a]; a++) {
        for (int b = 0; argv[a][b]; b++)
            max += my_strchr(argv[a][b], "<>|;&");
        max++;
    }
    new = please_malloc(max);
    for (int a = 0; argv[a] && max > count && count >= 0; a++) {
        count = send_in_new_argv(new, count, argv[a], 0);
    }
    mygetfree(argv);
    if (count < 0) {
        my_printf("Invalid null argument\n");
        mygetfree(new);
        return NULL;
    }
    new[count] = NULL;
    return new;
}
