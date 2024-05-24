/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

static long get_large_file_size(const char *path)
{
    DIR *dirp = opendir(path);
    long largest_size = -1;
    struct dirent *entry = readdir(dirp);
    struct stat st;
    char full_path[1024];
    int i = 0;

    while (entry != NULL) {
        my_strcpy(full_path, path);
        my_strcat(full_path, "/");
        my_strcat(full_path, entry->d_name);
        lstat(full_path, &st);
        if (st.st_size > largest_size)
            largest_size = st.st_size;
        i++;
        entry = readdir(dirp);
    }
    closedir(dirp);
    return largest_size;
}

static void print_inf(char *d, struct dirent *e, struct stat *s, char const *p)
{
    struct group *grp;
    struct passwd *pwd;
    int biggest_number = count_numbers(get_large_file_size(p));
    int difference = 0;

    grp = getgrgid(s->st_gid);
    pwd = getpwuid(s->st_uid);
    my_printf("%ld %s  %s  ", (long)s->st_nlink, pwd->pw_name, grp->gr_name);
    difference = biggest_number - count_numbers((long)s->st_size);
    if (count_numbers((long)s->st_size) > 1)
        for (int i = 0; i < difference; i++)
            my_printf(" ");
    else
        for (int i = 0; i < difference - 1; i++)
            my_printf(" ");
    my_printf("%ld ", (long)s->st_size);
    my_printf("%s %s\n", d, e->d_name);
}

static void infos(char *d, struct dirent *e, struct stat *s, char const *p)
{
    if (e->d_name[0] != '.') {
        print_permessions(s);
        print_inf(d, e, s, p);
    }
}

static void info_a(char *d, struct dirent *e, struct stat *s, char const *p)
{
    print_permessions(s);
    print_inf(d, e, s, p);
}

static int count_entries(DIR *dirp)
{
    struct dirent *entry = readdir(dirp);
    int size = 0;

    while (entry != NULL) {
        size++;
        entry = readdir(dirp);
    }
    return size;
}

static struct dirent **c_entries(DIR *dirp, int *size, flags flag)
{
    struct dirent **e;
    struct dirent *entry;
    int i = 0;

    *size = count_entries(dirp);
    e = malloc((*size) * sizeof(struct dirent *));
    entry = readdir(dirp);
    while (entry != NULL) {
        e[i] = entry;
        i++;
        entry = readdir(dirp);
    }
    if (flag.t == true)
        sort_entries_ls_l_t(e, *size);
    else
        sort_entries(e, *size);
    return e;
}

void copy_path(char full[1024], char const *p, struct dirent **e, int i)
{
    my_strcpy(full, p);
    my_strcat(full, "/");
    my_strcat(full, e[i]->d_name);
}

void my_ls_l(int argc, char **argv, char const *path, flags *present_flags)
{
    DIR *dirp = opendir(path);
    int num_entries = 0;
    struct dirent **entries = c_entries(dirp, &num_entries, *present_flags);
    struct stat st;
    char *dest;
    char full_path[1024];
    long total_blocks = calculate_total_blocks(entries, num_entries, path);

    print_total_blocks(total_blocks);
    for (int i = 0; i < num_entries; i++) {
        copy_path(full_path, path, entries, i);
        lstat(full_path, &st);
        dest = my_strninterval(ctime(&st.st_mtime), 4, 16);
        if (present_flags->a == true)
            info_a(dest, entries[i], &st, path);
        else
            infos(dest, entries[i], &st, path);
        free(dest);
    }
    free(entries);
}

void my_ls_l_r(int argc, char **argv, char const *path, flags *present_flags)
{
    DIR *dirp = opendir(path);
    int num_entries = 0;
    struct dirent **entries = c_entries(dirp, &num_entries, *present_flags);
    struct stat st;
    char *dest;
    char full_path[1024];
    long total_blocks = calculate_total_blocks(entries, num_entries, path);

    print_total_blocks(total_blocks);
    for (int i = num_entries - 1; i >= 0; i--) {
        copy_path(full_path, path, entries, i);
        lstat(full_path, &st);
        dest = my_strninterval(ctime(&st.st_mtime), 4, 16);
        if (present_flags->a == true)
            info_a(dest, entries[i], &st, path);
        else
            infos(dest, entries[i], &st, path);
        free(dest);
    }
    free(entries);
}
