/*
** EPITECH PROJECT, 2024
** My.H
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <dirent.h>
    #include <signal.h>
    #include <time.h>
    #include <ctype.h>
    #include <termios.h>
    #include <glob.h>
    #include <libgen.h>
    #define MAX_BUFFER 4096
    #define READ_END 0
    #define WRITE_END 1

typedef enum type_after {
    NONE = 0,
    AND,
    OR,
    MORE,
    PAR
} type_after_t;

typedef enum type {
    NO_TYPE = 0,
    SIMPLE = 1,
    DOUBLE = 2
} type_t;

typedef struct history_s {
    char *line_com;
    char *clock;
    int nb;
    struct history_s *next;
} history_t;

typedef struct line_com {
    type_after_t type;
    struct line_com *pipe;
    type_t in_t;
    type_t out_t;
    char *in;
    char *out;
    char **comm;
    char *disp_com;
    struct line_com *next;
    char **local_env;
} line_com_t;

typedef struct {
    line_com_t *new;
    line_com_t *act;
    line_com_t *piped;
    int len_malloc;
    int argv_in_comm;
    int test;
} InputOutputHandler_t;

typedef struct {
    char **env;
} local_env_t;

typedef struct line_edit_s {
    int length;
    char *buffer;
    int cursor_pos;
    char *buf;
    char *clipboard;
    int prompt;
} line_edit_t;


typedef struct general_s {
    char *actual_line;
    char *clipboard;
    int len;
    int pos_in_hist;
    int test;
    history_t *in_the_past;
    history_t **historic;
} general_t;

line_com_t *transformchar(char *str, int cpt_word, history_t **historic,
    char **env);
int my_strnlen(char *str, char carac);
char *my_strduplen(char *str, int len);
void my_strcpy(char *dest, const char *src);
int my_commands(char **argum, char *first, char ***env, __pid_t child_pid);
bool list_my_commands(char **argum, char *first_arg);
int print_env(char **env, char **argum);
int set_env(char *key, char ***env, const char *pwd, int b);
void myy_strcat(char *s1, const char *s2);
void my_strncpy(char *dest, char const *src, int n);
bool find_letter(const char *s, const char letter);
char *setbin(char *exe, char **env);
int my_perror(char *str, char *str2, char *str3, char *str4);
int too_many_setenv(void);
int check_pid_and_echo(__pid_t child_pid, line_com_t *command, int test,
    history_t **historic);
void add_historic(history_t **historic, char *argum);
void view_history(history_t **historic, char *argum);
char *check_in_path(char *env, int i, char *exe);
char *search_path(char **env, char *exe);
void free_historic(history_t **historic);
int secret_command(__pid_t child_pid, char ***env);
int child_result(int child_pid, line_com_t *command, char ***env, int test);
int cd_handler(char **argum, char ***env);
int unset_env(char **argum, char ***env);
line_com_t *magicinputoutput(char **argv);
int ndup(int a, char *str, int i);
int check_error(line_com_t **command);
void close_pipes(int **pipes, int num_commands, line_com_t **command);
void check_in_out(line_com_t **command, int i, int **pipes);
char *history_exclamtion(char *exe, history_t **history);
void remove_extra_spaces(char *str);
int voir_si_car(char *str);
line_com_t *magicinputoutput(char **argv);
int ndup(int a, char *str, int i);
int check_error(line_com_t **command);
void close_pipes(int **pipes, int num_commands, line_com_t **command);
void check_in_out(line_com_t **command, int i, int **pipes);
line_com_t *sort_my_old_transformchar(char **argv, history_t **historic,
    char *str);
char **check_rubbish(char **argv);
char **please_malloc(int max);
int send_in_new_argv(char **new, int count, char *argva, int b);
int *create_var_int(int f, int s, int t);
char **mygetfree(char **argv);
int have_a_delimiter(int *fir_ct, int b, char *ar, char **new);
void add_disp_command_error(line_com_t *command);
int my_strchr(char carac, char *orig);
char **more_argv(char **argv, char **new);
int set_command(char **argum, char ***env, char *first);
int ampersand(char **argum, char ***env);
void crochet(line_com_t **command, char ***env);
char *new_command(line_com_t *command __attribute__((unused)),
    char *executable, char *testline, general_t *general);
int alias(char **argum);
char *get_file_content(const char *filename);

void last_free(char ***enve, char *testline, general_t *general);
char *gettheline(char *exe, char *mem,
    general_t *general, history_t **historic);
char *line_edit(line_edit_t *edition, general_t *general,
    history_t **historic);
void ctrl_h(line_edit_t *edition);
void suppr(line_edit_t *edition);
void handle_character_input(char c, line_edit_t *edition, general_t *general);
void update_display(line_edit_t *edition, general_t *general);
int arrow_pressed(char *seq, line_edit_t *edition, general_t *general);
char *remove_in_str(char *str, int pos, int length);
void ctrl_k(line_edit_t *edition);
void ctrl_w(line_edit_t *edition);
char *add_end_string(char *str, char *str_added);
void ctrl_y(line_edit_t *edition);
void personnalize_my_prompt(int test, line_edit_t *edition);
void save_actual_line(general_t *general, line_edit_t *edition);
int main_condition(line_edit_t *edition, general_t *general);
char *classic_getline(void);
int have_a_delimiter(int *fir_ct, int b, char *ar, char **new);
void add_disp_command_error(line_com_t *command);
int my_strchr(char carac, char *orig);
char **more_argv(char **argv, char **new);
line_com_t *init_line_command(int type);
int handle_pipe(line_com_t **piped, line_com_t **act, int *argv_in_comm,
    int *max_arg);
int handle_semicolon(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg);
void handle_default(line_com_t *piped, char *arg, int *argv_in_comm);
int handle_and(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg);
int handle_or(line_com_t **act, line_com_t **piped,
    int *argv_in_comm, int *max_arg);
void include_pipe(InputOutputHandler_t *handler, char *arg,
    char **argv, int a);
void handle_input_output(line_com_t *piped, char *arg, int *test,
    int *argv_in_comm);
char *replace_backticks(char *str, char **env, int count, char *new);

char *replace_in_str(char *str, char *str_removed, char *str_added,
    int pos_removed);
char *remove_end_string(char *str, int count);
char *get_file_content(const char *filename);
#endif /*MY_H_*/
