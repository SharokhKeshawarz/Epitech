/*
** EPITECH PROJECT, 2024
** alias
** File description:
** I have to do it in stead of the one who was in charge
*/

#include "../include/pmy.h"
#include "../include/my.h"

int append_to_file(const char *filename, const char *content)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        perror("Erreur lors de la création du fichier");
        return -1;
    }
    if (write(fd, content, my_strlen(content)) == -1) {
        perror("Erreur lors de l'écriture dans le fichier");
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

void new_alias(char **argum)
{
    append_to_file(".stock-alias", argum[1]);
    append_to_file(".stock-alias", "\t");
    for (int i = 2; argum[i] != NULL; i++) {
        append_to_file(".stock-alias", argum[i]);
        append_to_file(".stock-alias", " ");
    }
    append_to_file(".stock-alias", "\n");
}

void is_there_alias(char **argum, char *content)
{
    char **array_line;
    char *save = NULL;

    if (content[0] == '\0' || content == NULL)
        return;
    array_line = my_str_to_word_array(content, "\n");
    for (int i = 0; array_line[i] != NULL; i++)
        if (strncmp(argum[1], array_line[i], strlen(argum[1])) == 0 &&
        array_line[i][strlen(argum[1])] == '\t')
            save = array_line[i];
    if (save == NULL)
        return;
    printf("%s\n", &save[strlen(argum[1]) + 1]);
    for (int i = 0; array_line[i]; i++)
        free(array_line[i]);
    free(array_line);
}

int alias(char **argum)
{
    int fd = open(".stock-alias", O_RDWR | O_CREAT | O_APPEND, 0644);
    char *content = get_file_content(".stock-alias");

    if (argum[1] == NULL) {
        if (content[0] == '\0' || content == NULL)
            return 0;
        printf("%s", content);
    } else if (argum[2] == NULL) {
        is_there_alias(argum, content);
    } else
        new_alias(argum);
    free(content);
    close(fd);
    return 0;
}
