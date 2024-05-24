/*
** EPITECH PROJECT, 2024
** special case.c
** File description:
** Will detect all anomalies.
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

void update_display(line_edit_t *edition, general_t *general)
{
    write(STDOUT_FILENO, "\r\033[K", 4);
    if (isatty(0))
        personnalize_my_prompt(general->test, edition);
    write(STDOUT_FILENO, edition->buffer, edition->length);
    sprintf(edition->buf, "\033[%dG", edition->cursor_pos + 1);
    write(STDOUT_FILENO, edition->buf, strlen(edition->buf));
}

void handle_character_input(char c, line_edit_t *edition, general_t *general)
{
    if (edition->length < 1023) {
        memmove(edition->buffer + (edition->cursor_pos - edition->prompt) + 1,
                edition->buffer + (edition->cursor_pos - edition->prompt),
                edition->length - (edition->cursor_pos - edition->prompt));
        edition->buffer[edition->cursor_pos - edition->prompt] = c;
        edition->length++;
        edition->cursor_pos++;
    }
}

void suppr(line_edit_t *edition)
{
    if (edition->cursor_pos > edition->prompt) {
        edition->cursor_pos--;
        remove_in_str(edition->buffer, edition->cursor_pos - edition->prompt,
        edition->length);
        edition->length--;
    }
}
