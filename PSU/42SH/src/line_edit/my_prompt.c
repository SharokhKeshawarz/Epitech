/*
** EPITECH PROJECT, 2024
** my prompt
** File description:
** Hello ? How are you ? Where am I ? Can I write ? Of course.
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

int my_strlen_for_term(const char *str)
{
    const char target[] = "❯";
    int len = 0;

    while (str[len]) {
        if (strncmp(&str[len], target, sizeof(target) - 1) == 0)
            break;
        len++;
    }
    return len + 1;
}

int nb_digits(int nb)
{
    int i = 1;

    while (nb >= 10) {
        i++;
        nb = nb / 10;
    }
    return i;
}

void personnalize_my_prompt(int test, line_edit_t *edition)
{
    char cwd[1024];
    char *basename_cwd = NULL;

    edition->prompt = 0;
    if (test == 0) {
        my_printf("\033[1;32m➜  \033[0;0m");
    } else {
        my_printf("\033[1;31m<%d> ➜  \033[0;0m", test);
        edition->prompt += nb_digits(test) + 3;
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        basename_cwd = basename(cwd);
        if (basename_cwd)
            my_printf("\033[1;36m%s \033[1;33m❯\033[0;0m ", basename_cwd);
    }
    edition->prompt += my_strlen_for_term(basename_cwd) + 5;
}
