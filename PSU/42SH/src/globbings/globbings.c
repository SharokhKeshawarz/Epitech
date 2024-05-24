/*
** EPITECH PROJECT, 2024
** globbings.c
** File description:
** globbings
*/

#include "../include/pmy.h"
#include "../include/my.h"

void verifier_globbing(char *str)
{
    glob_t glob_result;

    if (glob(str, 0, NULL, &glob_result) == 0) {
        for (size_t i = 0; i < glob_result.gl_pathc; i++) {
            printf("%s ", glob_result.gl_pathv[i]);
        }
        globfree(&glob_result);
        printf("\n");
        exit(0);
    } else
        printf("ls: No match.\n");
}

void crochet(line_com_t **command, char ***env)
{
    if ((*command)->comm[1] != NULL){
        if (strstr((*command)->comm[1], "/[") != NULL ||
        strstr((*command)->comm[1], "/*") != NULL){
            verifier_globbing((*command)->comm[1]);
        } else
            execve((*command)->comm[0], (*command)->comm, *env);
    } else
        execve((*command)->comm[0], (*command)->comm, *env);
}
