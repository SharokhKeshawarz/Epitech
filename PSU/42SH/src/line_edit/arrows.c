/*
** EPITECH PROJECT, 2024
** arrows
** File description:
** An action if one of the arrows is pressed
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

void save_actual_line(general_t *general, line_edit_t *edition)
{
    if (general->pos_in_hist == 0) {
        if (general->actual_line != NULL) {
            free(general->actual_line);
            general->actual_line = NULL;
        }
        general->actual_line = malloc(sizeof(char) * (edition->length + 1));
        general->len = edition->length;
        for (int i = 0; i < edition->length; i++)
            general->actual_line[i] = edition->buffer[i];
        general->actual_line[edition->length] = '\0';
    }
}

static void modify_from_hist(line_edit_t *edition, history_t *travel)
{
    for (int i = 0; i < edition->length; i++) {
        edition->buffer[i] = 0;
    }
    for (int i = 0; i < my_strlen(travel->line_com) - 1; i++) {
        edition->buffer[i] = travel->line_com[i];
    }
    edition->cursor_pos = my_strlen(travel->line_com) + edition->prompt - 1;
    edition->length = my_strlen(travel->line_com) - 1;
}

static void arrow_up(line_edit_t *edition, general_t *general)
{
    history_t *travel = general->in_the_past;

    general->pos_in_hist++;
    for (int i = 0; i < general->pos_in_hist - 1; i++)
        travel = travel->next;
    if (travel == NULL || travel->next == NULL) {
        general->pos_in_hist--;
        return;
    }
    modify_from_hist(edition, travel);
}

static void modify_from_no_hist(line_edit_t *edition, general_t *general)
{
    for (int i = 0; i < edition->length; i++) {
        edition->buffer[i] = 0;
    }
    if (general->actual_line != NULL) {
        for (int i = 0; i < my_strlen(general->actual_line); i++) {
            edition->buffer[i] = general->actual_line[i];
        }
        edition->cursor_pos = my_strlen(general->actual_line) +
        edition->prompt;
        edition->length = my_strlen(general->actual_line);
    } else {
        edition->cursor_pos = edition->prompt;
        edition->length = 0;
    }
}

static void arrow_down(line_edit_t *edition, general_t *general)
{
    history_t *travel = general->in_the_past;

    general->pos_in_hist--;
    for (int i = 0; i < general->pos_in_hist - 1; i++)
        travel = travel->next;
    if (general->pos_in_hist == 0) {
        modify_from_no_hist(edition, general);
    } else
        modify_from_hist(edition, travel);
}

static int move_cursor(line_edit_t *edition, char *seq, general_t *general)
{
    if (seq[1] == 'C' && edition->cursor_pos <
    edition->length + edition->prompt) {
        edition->cursor_pos++;
    } else if (seq[1] == 'D' && edition->cursor_pos > edition->prompt)
        edition->cursor_pos--;
    if (seq[1] == 'A') {
        arrow_up(edition, general);
    } else if (seq[1] == 'B' && general->pos_in_hist != 0) {
        arrow_down(edition, general);
    }
    return edition->cursor_pos;
}

int arrow_pressed(char *seq, line_edit_t *edition, general_t *general)
{
    if (read(STDIN_FILENO, &seq[0], 1) == 1 && seq[0] == '[') {
        if (read(STDIN_FILENO, &seq[1], 1) == 1) {
            edition->cursor_pos = move_cursor(edition, seq, general);
        }
    }
    return edition->cursor_pos;
}
