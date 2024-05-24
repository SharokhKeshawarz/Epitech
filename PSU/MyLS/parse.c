/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

int is_flag_present(char *value, flags present_flags)
{
    int flag = 0;

    if (value == 0)
        return -1;
    if (value[0] == '-' && value != NULL) {
        if (present_flags.a == 1)
            flag ++;
        if (present_flags.r == 1)
            flag++;
        if (present_flags.d == 1)
            flag++;
        if (present_flags.l == 1)
            flag++;
        if (present_flags.t == 1)
            flag++;
        if (present_flags.R == 1)
            flag++;
    }
    return flag > 0 ? flag : 0;
}

static void init_flags(flags *present_flags)
{
    present_flags->a = false;
    present_flags->r = false;
    present_flags->d = false;
    present_flags->l = false;
    present_flags->t = false;
    present_flags->R = false;
}

static void check_attached_flags(char *value, int i, flags *present_flags)
{
    if (value[i] == 'a')
        present_flags->a = true;
    if (value[i] == 'r')
        present_flags->r = true;
    if (value[i] == 'd')
        present_flags->d = true;
    if (value[i] == 'l')
        present_flags->l = true;
    if (value[i] == 't')
        present_flags->t = true;
    if (value[i] == 'R')
        present_flags->R = true;
}

static void parse_seperated_flags(char *value, flags *present_flags)
{
    if (my_strlen(value) == 2) {
        if (my_strcmp(value, "-a") == 0)
            present_flags->a = true;
        if (my_strcmp(value, "-r") == 0)
            present_flags->r = true;
        if (my_strcmp(value, "-d") == 0)
            present_flags->d = true;
        if (my_strcmp(value, "-l") == 0)
            present_flags->l = true;
        if (my_strcmp(value, "-t") == 0)
            present_flags->t = true;
        if (my_strcmp(value, "-R") == 0)
            present_flags->R = true;
    }
}

static void parse_attached_flags(char *value, flags *present_flags)
{
    if (my_strlen(value) > 2) {
        for (int i = 0; value[i] != '\0'; i++)
            check_attached_flags(value, i, present_flags);
    }
}

flags *parse(int argc, char **argv)
{
    flags *present_flags = (flags *)malloc(sizeof(flags));

    if (present_flags == NULL)
        return NULL;
    init_flags(present_flags);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            parse_seperated_flags(argv[i], present_flags);
            parse_attached_flags(argv[i], present_flags);
        }
    }
    return present_flags;
}
