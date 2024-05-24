/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

static int count_with_hidden_elements(char const *path)
{
    DIR *dirp = opendir(path);
    struct dirent *entry;
    int count = 0;

    if (dirp == NULL) {
        perror("Error opening directory");
        return 84;
    }
    entry = readdir(dirp);
    while (entry != NULL) {
        count++;
        entry = readdir(dirp);
    }
    closedir(dirp);
    return count;
}

static int count_without_hidden_elements(char const *path)
{
    DIR *dirp = opendir(path);
    struct dirent *entry;
    int count = 0;

    if (dirp == NULL) {
        perror("Error opening directory");
        return 84;
    }
    entry = readdir(dirp);
    while (entry != NULL) {
        if (entry->d_name[0] != '.')
            count++;
        entry = readdir(dirp);
    }
    closedir(dirp);
    return count;
}

int count_elements(char const *path, flags present_flags)
{
    if (present_flags.a == 1) {
        if (count_with_hidden_elements(path) == 84)
            return 84;
        else
            return count_with_hidden_elements(path);
    } else {
        if (count_without_hidden_elements(path) == 84)
            return 84;
        else
            return count_without_hidden_elements(path);
    }
    return 0;
}

static int fill_without_hidden(char const *path, char **array)
{
    DIR *dirp = opendir(path);
    struct dirent *entry;
    int i = 0;

    if (dirp == NULL) {
        perror("Error opening directory");
        return 84;
    }
    entry = readdir(dirp);
    while (entry != NULL) {
        if (entry->d_name[0] != '.') {
            array[i] = my_strdup(entry->d_name);
            i++;
        }
        entry = readdir(dirp);
    }
    closedir(dirp);
    return 0;
}

static int fill_with_hidden(char const *path, char **array)
{
    DIR *dirp = opendir(path);
    struct dirent *entry;
    int i = 0;

    if (dirp == NULL) {
        perror("Error opening directory");
        return 84;
    }
    entry = readdir(dirp);
    while (entry != NULL) {
        array[i] = my_strdup(entry->d_name);
        i++;
        entry = readdir(dirp);
    }
    closedir(dirp);
    return 0;
}

char **create_array(char const *path, flags present_flags)
{
    int elements = count_elements(path, present_flags);
    char **array = (char **)malloc(elements * sizeof(char *));

    if (elements == 84)
        return NULL;
    if (present_flags.a == true) {
        if (fill_with_hidden(path, array) == 84)
            return NULL;
    } else {
        if (fill_without_hidden(path, array) == 84)
            return NULL;
    }
    if (present_flags.t == true)
        sort_entries_ls_t(array, elements);
    else
        custom_sort(array, elements);
    return array;
}
