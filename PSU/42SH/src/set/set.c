/*
** EPITECH PROJECT, 2024
** set.c
** File description:
** set
*/

#include "../../include/pmy.h"

char **create_token_array(char **argum)
{
    char *token;
    char **temp_argum = malloc(sizeof(char *) * 3);
    int index = 0;

    for (index = 0; argum[index] != NULL; index++);
    if (index == 1) {
        printf("set [NAME] = OPTIONAL->[VALUE]\n");
        return NULL;
    }
    index = 0;
    for (int i = 1; argum[i] != NULL; i++) {
        token = strtok(argum[i], "=");
        while (token != NULL) {
            temp_argum[index] = strdup(token);
            token = strtok(NULL, "=");
            index++;
        }
    }
    temp_argum[index] = NULL;
    return temp_argum;
}

static char *set_path(char ***env)
{
    int i = 0;
    char cwd[1024];
    char *full_path = malloc(sizeof(char) * 1024);

    for (i = 0; (*env)[i] != NULL; i++);
    getcwd(cwd, sizeof(cwd));
    sprintf(full_path, "%s/%s", cwd, ".local-env");
    set_env("LOCAL_ENV", env, full_path, 1);
    return full_path;
}

int set_command(char **argum, char ***env, char *first)
{
    int fd = open(".local-env", O_RDWR | O_CREAT | O_APPEND, 0644);
    char **temp_argum = create_token_array(argum);
    char *temp_env_path = set_path(env);

    if (temp_argum == NULL)
        return 84;
    if (!temp_argum[1])
        temp_argum[1] = strdup("");
    dprintf(fd, "%s=%s\n", temp_argum[0], temp_argum[1]);
    for (int i = 0; i < 3; i++)
        free(temp_argum[i]);
    free(temp_argum);
    free(temp_env_path);
    close(fd);
    return 0;
}
