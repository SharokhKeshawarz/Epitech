/*
** EPITECH PROJECT, 2024
** utility str
** File description:
** Is composed of some of the most important str functions
*/

#include "../include/pmy.h"
#include "../include/my.h"

char *get_file_content(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *content = NULL;
    off_t size;

    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    content = malloc(sizeof(char) * (size + 1));
    if (read(fd, content, size) == -1) {
        perror("Erreur lors de la lecture du fichier");
        free(content);
        close(fd);
        return NULL;
    }
    content[size] = '\0';
    close(fd);
    return content;
}

char *remove_end_string(char *str, int count)
{
    char *cpy_str = malloc(sizeof(char) * (strlen(str) + 1));
    int i;

    strcpy(cpy_str, str);
    free(str);
    str = malloc(sizeof(char) * (strlen(cpy_str) - count + 1));
    for (i = 0; i < strlen(cpy_str) - count; i++)
        str[i] = cpy_str[i];
    str[i] = '\0';
    free(cpy_str);
    return str;
}

char *replace_in_str(char *str, char *str_removed, char *str_added,
    int pos_removed)
{
    char *cpy = malloc(sizeof(char) * (strlen(&str[pos_removed]) -
    strlen(str_removed) + 1));

    cpy = strcpy(cpy, &str[pos_removed + strlen(str_removed)]);
    str = remove_end_string(str, strlen(str) - pos_removed);
    str = add_end_string(str, str_added);
    str = add_end_string(str, cpy);
    free(cpy);
    return str;
}
