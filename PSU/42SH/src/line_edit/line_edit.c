/*
** EPITECH PROJECT, 2024
** main
** File description:
** mastermind
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

static void disable_rawmode(struct termios *orig_termios)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
}

static void enable_rawmode(struct termios *orig_termios)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, orig_termios);
    raw = *orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

char *remove_in_str(char *str, int pos, int length)
{
    int i;

    str[pos] = 0;
    for (i = pos; i < length; i++)
        str[i] = str[i + 1];
    str[i] = 0;
    return str;
}

static line_edit_t *init_edit(line_edit_t *edition,
    general_t *general, history_t **historic)
{
    general->actual_line = NULL;
    general->in_the_past = *historic;
    general->pos_in_hist = 0;
    edition->buffer = malloc(sizeof(char) * 1025);
    for (int i = 0; i < 1024; i++)
        edition->buffer[i] = 0;
    edition->buf = malloc(sizeof(char) * 64);
    edition->length = 0;
    edition->cursor_pos = 0;
    edition->clipboard = general->clipboard;
    return edition;
}

char *add_end_string(char *str, char *str_added)
{
    char *cpy_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i;

    my_strcpy(cpy_str, str);
    free(str);
    str = malloc(sizeof(char) * (my_strlen(cpy_str) +
    my_strlen(str_added) + 1));
    for (i = 0; cpy_str[i] != '\0'; i++)
        str[i] = cpy_str[i];
    for (i; str_added[i - my_strlen(cpy_str)] != '\0'; i++)
        str[i] = str_added[i - my_strlen(cpy_str)];
    str[i] = '\0';
    free(cpy_str);
    return str;
}

static char *free_line_edit(line_edit_t *edition)
{
    free(edition->buffer);
    free(edition);
    return NULL;
}

static void beginning_edit(general_t *general,
    line_edit_t *edition, history_t **historic)
{
    if (general->actual_line != NULL) {
        free(general->actual_line);
        general->actual_line = NULL;
    }
    edition = init_edit(edition, general, historic);
    if (isatty(0))
        personnalize_my_prompt(general->test, edition);
    edition->cursor_pos = edition->prompt;
}

static void ending_edit(general_t *general, line_edit_t *edition)
{
    write(STDOUT_FILENO, "\n", 1);
    free(edition->buf);
    general->clipboard = edition->clipboard;
    edition->buffer[edition->length] = '\0';
    if (general->actual_line != NULL) {
        free(general->actual_line);
        general->actual_line = NULL;
    }
}

char *line_edit(line_edit_t *edition, general_t *general, history_t **historic)
{
    struct termios orig_termios;
    int error = 0;
    char end_space[2] = {" "};

    enable_rawmode(&orig_termios);
    beginning_edit(general, edition, historic);
    while (1) {
        error = main_condition(edition, general);
        if (error == 1)
            break;
        if (error == 84) {
            disable_rawmode(&orig_termios);
            ending_edit(general, edition);
            return free_line_edit(edition);
        }
    }
    disable_rawmode(&orig_termios);
    ending_edit(general, edition);
    return add_end_string(edition->buffer, end_space);
}
