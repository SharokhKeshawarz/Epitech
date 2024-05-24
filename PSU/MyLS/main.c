/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#include "include/ls.h"

int error_checking_dirp(DIR *dirp)
{
    if (dirp == NULL) {
        perror("Error oepning directory");
        return 84;
    }
}

static int check_fd(char const *path)
{
    DIR *dirp = opendir(path);
    struct dirent *entry;
    struct stat st;

    if (error_checking_dirp(dirp) == 84)
        return 84;
    entry = readdir(dirp);
    if (lstat(path, &st) != 0) {
        perror("Error getting file stat");
        return 84;
    }
    while (entry != NULL) {
        if (S_ISDIR(st.st_mode) || S_ISREG(st.st_mode)) {
            closedir(dirp);
            return 1;
        }
        entry = readdir(dirp);
    }
    closedir(dirp);
    return 0;
}

static int check_argc_one(int argc, char **argv, flags *flag)
{
    if (argc == 1)
        my_ls(argc, argv, ".", flag);
    return 0;
}

static int check_contains_fd(int argc, char **argv, flags *flag, int *c_fd)
{
    for (int i = 1; i < argc; i++)
        if (is_flag_present(argv[i], *flag) == 0 && check_fd(argv[i]) == 1)
            *c_fd = 1;
    return 0;
}

static int check_no_fd(int c, char **v, int i, flags *f)
{
    if (is_flag_present(v[i], *f) > 0 && f->l == 0) {
        my_ls(c, v, ".", f);
        return 0;
    }
    if (is_flag_present(v[i], *f) > 0 && f->l == 1 && f->r == 0) {
        my_ls_l(c, v, ".", f);
        return 0;
    }
    if (is_flag_present(v[i], *f) > 0 && f->l == 1 && f->r == 1) {
        my_ls_l_r(c, v, ".", f);
    }
}

static int check_lr_flag_false(int argc, char **argv, flags *flag)
{
    for (int i = 1; i < argc; i++) {
        if (is_flag_present(argv[i], *flag) == 0) {
            print_double_dots(argv, i);
            my_ls_l(argc, argv, argv[i], flag);
            space(argc, i);
        }
    }
    return 0;
}

static int check_lr_flag_true(int argc, char **argv, flags *flag)
{
    for (int i = 1; i < argc; i++) {
        if (is_flag_present(argv[i], *flag) == 0) {
            print_double_dots(argv, i);
            my_ls_l_r(argc, argv, argv[i], flag);
            space(argc, i);
        }
    }
    return 0;
}

static int print_normal(int argc, char **argv, flags *flag)
{
    for (int i = 1; i < argc; i++)
        if (is_flag_present(argv[i], *flag) == 0)
            my_ls(argc, argv, argv[i], flag);
    return 0;
}

static int check_r_for_l(int argc, char **argv, flags *flag)
{
    if (flag->l == true) {
        if (flag->r == false) {
            check_lr_flag_false(argc, argv, flag);
            return 0;
        }
        if (flag->r == true) {
            check_lr_flag_true(argc, argv, flag);
            return 0;
        }
    }
}

int main(int argc, char **argv)
{
    flags *flag = parse(argc, argv);
    int contains_fd = 0;

    check_argc_one(argc, argv, flag);
    check_contains_fd(argc, argv, flag, &contains_fd);
    if (contains_fd == 0) {
        for (int i = 1; i < argc; i++) {
            check_no_fd(argc, argv, i, flag);
            return 0;
        }
        return 84;
    } else if (flag->l == true) {
        check_r_for_l(argc, argv, flag);
        return 0;
    }
    print_normal(argc, argv, flag);
    return 0;
}
