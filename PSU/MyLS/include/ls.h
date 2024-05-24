/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
*/

#ifndef LS_H
    #define LS_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include "my.h"

// FLAG
typedef struct flags {
    int a;
    int r;
    int d;
    int l;
    int t;
    int R;
} flags;

enum bool {
    false,
    true
};

// LIB
char *my_strdup(char const *);
char *my_strninterval(char const *, int, int);
char *my_strcpy(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcat(char *, char const *);
char *my_strlen(char const *);
int my_strcasecmp(char const *, char const *);
int count_numbers(long);
int my_tolower(int);

// PARSE
int is_flag_present(char *, flags);
static void init_flags(flags *);
static void check_attached_flags(char *, int, flags *);
static void parse_seperated_flags(char *, flags *);
static void parse_attached_flags(char *, flags*);
flags *parse(int, char **);

// SORT
static void check_and_swap(char **, int, int *);
void custom_sort(char **, int);
static void swap_entries_t(char **, char **);
static int should_swap_entries_ls_t(char *, char *);
static void swap_if_necessary_ls_t(char **, int, int);
void sort_entries_ls_t(char **, int);

// SORT L
static void check_and_swap_entries(struct dirent **, int, int *);
void sort_entries(struct dirent **, int);
static void swap_entries_ls_l_t(struct dirent **, struct dirent **);
static int should_swap_entries_ls_l_t(struct dirent *, struct dirent *);
static void swap_if_necessary_ls_l_t(struct dirent **, int, int);
void sort_entries_ls_l_t(struct dirent **, int);

// CREATE_ARRAY
static int count_with_hidden_elements(char const *);
static int count_without_hidden_elements(char const *);
int count_elements(char const *, flags);
static int fill_without_hidden(char const *, char **);
static int fill_with_hidden(char const *, char **);
char **create_array(char const *, flags);

// my_ls_l
void print_permessions(struct stat *);
static long get_large_file_size(char const *);
static void print_inf(char *, struct dirent *, struct stat *, char const *);
static void infos(char *, struct dirent *, struct stat *, char const *);
static void info_a(char *, struct dirent *, struct stat *, char const *);
static int count_entries(DIR *);
static struct dirent **c_entries(DIR *, int *, flags);
void copy_path(char full[1024], char const *, struct dirent **, int);
void my_ls_l(int, char **, char const *, flags *);
void my_ls_l_r(int, char **, char const *, flags *);

// LS
static void check_space_ls(char **, int, int);
int my_ls(int, char **, char const *, flags *);

#endif
