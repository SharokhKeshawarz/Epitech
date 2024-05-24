/*
** EPITECH PROJECT, 2024
** new command
** File description:
** Too big to fit in the main
*/

#include "../include/pmy.h"
#include "../include/my.h"

char *end_free(char *str)
{
    if (str != NULL)
        free(str);
    return NULL;
}

static bool big_condition(char *executable, int i, char *is_alias)
{
    if (strncmp(&executable[i], is_alias, strlen(is_alias)) == 0 &&
    !isalpha(executable[i + strlen(is_alias)]) &&
    !isdigit(executable[i + strlen(is_alias)]))
        return true;
    return false;
}

static char *init_save(char *save, char **all_alias, int z, char *is_alias)
{
    save = end_free(save);
    save = malloc(sizeof(char) * (strlen(all_alias[z]) -
    strlen(is_alias) + 2));
    save = strcpy(save, &all_alias[z][strlen(is_alias) + 1]);
    return save;
}

static char *init_real_alias(char *real_alias, char *is_alias)
{
    real_alias = malloc(sizeof(char) * (strlen(is_alias) + 1));
    real_alias = strcpy(real_alias, is_alias);
    return real_alias;
}

char *consider_alias(char *executable, int i)
{
    char **all_alias = my_str_to_word_array
    (get_file_content(".stock-alias"), "\n");
    char *is_alias = NULL;
    char *save = NULL;
    char *real_alias = NULL;

    for (int z = 0; all_alias[z] != NULL; z++) {
        is_alias = end_free(is_alias);
        is_alias = my_str_to_word_array(all_alias[z], "\t")[0];
        if (big_condition(executable, i, is_alias) == true) {
            save = init_save(save, all_alias, z, is_alias);
            real_alias = init_real_alias(real_alias, is_alias);
        }
    }
    if (save != NULL)
        executable = replace_in_str(executable, real_alias, save, i);
    save = end_free(save);
    real_alias = end_free(real_alias);
    is_alias = end_free(is_alias);
    return executable;
}

static char *content_local_var(char **content, char *local_var)
{
    char *result = NULL;

    for (int y = 0; content[y]; y++) {
        if (result != NULL)
            free(result);
        result = NULL;
        if (strncmp(&local_var[1], content[y], strlen(&local_var[1])) == 0) {
            result = malloc(sizeof(char) * (strlen(content[y]) -
            strlen(&local_var[1]) - 1));
            result = strcpy(result, &content[y][strlen(&local_var[1]) + 1]);
        }
    }
    return result;
}

char *consider_local_var(char *executable, int i)
{
    char local_var[5000] = {0};
    char **content = my_str_to_word_array
    (get_file_content(".local-env"), "\n");
    int try = 0;
    char *value;
    int x;

    if (executable[i] == '$') {
        local_var[0] = '$';
        for (x = i + 1; isalpha(executable[x]) || isdigit(executable[x]); x++)
            local_var[x - i] = executable[x];
        local_var[x - i + 1] = '\0';
        executable = replace_in_str(executable, local_var,
        content_local_var(content, local_var), i);
    }
    return executable;
}

char *new_command(line_com_t *command __attribute__((unused)),
    char *executable, char *testline, general_t *general)
{
    executable = gettheline(testline, NULL, general, general->historic);
    return executable;
}
